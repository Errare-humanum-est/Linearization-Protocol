--------------------------------------------------------------------------------
-- Linearization Protocol
--
-- Modification of the Linearization Protocol by
--  Vasilis Gavrielatos, Antonios Katsarakis
--
-- Modification ensures protocol safety at counter overflow
--  N.A. Oswald
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- Constants
--------------------------------------------------------------------------------
const
  -- Number of processors, each of which has its own private Cache.
  PROC_COUNT: 3;

  -- Cache Line Properties
  ADR_COUNT:   2;   -- Number address (CL)
  VAL_COUNT:   2;   -- Maximum value of CL entry 0..VAL_COUNT

  -- Network parameters.
  U_NET_MAX: 3*PROC_COUNT*ADR_COUNT;


--------------------------------------------------------------------------------
-- Types
--------------------------------------------------------------------------------
type
  Cache: scalarset(PROC_COUNT);   -- Unordered range of processors

  Address:   scalarset(ADR_COUNT);


  TSr: 0..VAL_COUNT;
  ids: 0..PROC_COUNT;


  MessageType: enum {     
            Inv,     
            Inv_Ack,
            Inv_N_Ack,     
            Update,
            Update_Ack,
            Wrap,
            Wrap_Ack,
            Wrap_Complete
            };

  CacheStates: enum {
          C_I_U,
          C_V,
          C_V_A,
          C_V_A_I,
          C_W_A,
          C_W_I,
          C_V_A_A,
          C_V_W_A,
          C_U_A,
          C_U_W
          };


  Message:
    record
      mtype: MessageType;
      src: Cache;
      adr: Address;
      TS:  TSr;
      id:  ids;
  end;

  CacheLine:
    record
      state: CacheStates;
      id:      ids;
      TS:      TSr;
      lid:     ids;
      inv_ack: ids;
      upd_ack: ids;
  end;

  CacheEntry:
    record
      CL: array [Address] of CacheLine;
  end;

  WState:
    record
      CL:     array [Address] of CacheStates;
  end;

-- }}}

--------------------------------------------------------------------------------
-- Variables
--------------------------------------------------------------------------------
var
  net:      array [Cache]    of multiset [U_NET_MAX] of Message;    -- unordered msg buffers
  caches:   array [Cache]    of CacheEntry;
  wstates:  array [Cache]    of WState;

  c_TS:     array[Address] of TSr;


--------------------------------------------------------------------------------
-- Invariant Check Functions
--------------------------------------------------------------------------------
function ValidEntry(): boolean;
var
  valid: boolean;
begin
  valid := false;
  for adr:Address do
    for i:Cache do
    if(caches[i].CL[adr].state = C_V_A | 
      caches[i].CL[adr].state = C_V |
      caches[i].CL[adr].state = C_W_A |
      caches[i].CL[adr].state = C_V_A_A |
      caches[i].CL[adr].state = C_V_W_A) then
      valid:=true;
      endif;
    endfor;
  endfor;

  return valid;
end;


--------------------------------------------------------------------------------
-- Send functions
--------------------------------------------------------------------------------
procedure Send(mtype:MessageType;
               dst:Cache;
               src:Cache;
               adr:Address;
               TS:TSr;
               id:ids);
var
  msg:Message;
begin
  msg.mtype := mtype;
  msg.src   := src;
  msg.adr   := adr;
  msg.TS   := TS;
  msg.id    := id;

  -- Unordered Network
  Assert (MultiSetCount(i:net[dst], true) < U_NET_MAX) "Too many messages";
  MultiSetAdd(msg, net[dst]);

end;

procedure Broadcast(mtype:MessageType; adr: Address; p:Cache);
begin
  -- Send broadcasts out 
  for cc:Cache do
    if (cc!=p) then
      Send(mtype, cc, p, adr, caches[p].CL[adr].TS, caches[p].CL[adr].id);
    endif;
  endfor;
end;


--------------------------------------------------------------------------------
-- Cache Function
--------------------------------------------------------------------------------
procedure AssignCacheID();
var
  id:ids;
begin
  id:=0;
  for i:Cache do
    id:=id+1;
    for adr: Address do
      caches[i].CL[adr].id:=id;
      caches[i].CL[adr].lid:=id;  
    endfor;
  endfor;
end;


--------------------------------------------------------------------------------
-- Error Function
--------------------------------------------------------------------------------
procedure ErrorUnhandledMsg();
begin
    error "Unhandled message type!";
end;

procedure CCErrorUnhandledMsg(msg:Message; p:Cache);
begin
    put "\n";
    put "ERROR TRACE TERMINAL STATE \n";
    put "Error State: ";
    put caches[p].CL[msg.adr].state;
    put "Message Type: ";
    put msg.mtype;
    put "\n";
    put "Message Source: ";
    put msg.src;
    put "\n\n";
    error "Unhandled message type!";
end;

procedure ErrorUnhandledState();
begin
    error "Unhandled state!";
end;


--------------------------------------------------------------------------------
-- Cache functions
--------------------------------------------------------------------------------
function Rec_Inv(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do
    if (msg.TS>ps.TS | (msg.TS=ps.TS & msg.id>ps.lid)) then
      ps.TS:=msg.TS;
      ps.lid:=msg.id;
      Send(Inv_Ack,msg.src,p,msg.adr,ps.TS,msg.id);
      return true;
    else
      Send(Inv_N_Ack,msg.src,p,msg.adr,ps.TS,msg.id);
    endif;
  endalias;

  return false;
end;

function Rec_Inv_Ack(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do

    if (msg.TS=ps.TS & msg.id=ps.id) then
      ps.inv_ack := ps.inv_ack+1;
      if (ps.inv_ack=PROC_COUNT-1) then

        Broadcast(Update, msg.adr, p);

        if msg.TS=VAL_COUNT then
          ps.TS:=0;
        endif;

        ps.inv_ack:=0;

        for i:Cache do
          wstates[i].CL[msg.adr]:=caches[i].CL[msg.adr].state;
        endfor;

        return true;

      endif;
    endif;
  endalias;

  return false;
end;

function Rec_Inv_N_Ack(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do
      ps.inv_ack := ps.inv_ack+1;
      if (ps.inv_ack=PROC_COUNT-1) then
        return true;
      endif;

  endalias;

  return false;
end;

function Rec_Update(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do

    Send(Update_Ack,msg.src,p,msg.adr,ps.TS,msg.id);

    if (msg.TS=ps.TS) then
      if msg.TS=VAL_COUNT then
        ps.TS:=0;
      endif;
      return true;
    endif;

  endalias;

  return false;
end;

function Rec_Update_Ack(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do
    ps.upd_ack := ps.upd_ack+1;

    if (ps.upd_ack=PROC_COUNT-1) then
      ps.upd_ack:=0;
      return true;
    endif;

  endalias;

  return false;
end;

function Rec_Wrap_Ack(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do
    ps.upd_ack := ps.upd_ack+1;

    if (ps.upd_ack=PROC_COUNT-1) then
      ps.upd_ack:=0;
      return true;
    endif;

  endalias;

  return false;
end;

function Test_Wrap(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do

    if ps.TS = 0 then
      return true;
    endif;

  endalias;

  return false;
end;

procedure Issue_Wrap(msg:Message; p:Cache);
begin
  alias ps:caches[p].CL[msg.adr] do
    Broadcast(Wrap, msg.adr, p);
  endalias;
end;

procedure Issue_Wrap_Complete(msg:Message; p:Cache);
begin
  alias ps:caches[p].CL[msg.adr] do
    Broadcast(Wrap_Complete, msg.adr, p);
  endalias;
end;

procedure UpdateTS(p:Cache; adr: Address);
begin
  alias ps:caches[p].CL[adr] do  
    -- Update transaction count
    if (ps.TS<VAL_COUNT) then
      ps.TS:=ps.TS+1;
    else 
      ps.TS:=0;
    endif;
  endalias;
end;

function CacheReceive(msg:Message; p:Cache) : boolean;
begin
  alias adr:msg.adr do
  alias ps:caches[p].CL[adr] do
    switch ps.state

      case C_I_U:
          switch msg.mtype
            case Inv:
                if Rec_Inv(msg,p) then
                  ps.state :=  C_I_U;
                endif;

            case Inv_Ack:
                -- remove old Inv_Ack from input queue
                return true;

            case Update:
                if Rec_Update(msg,p) then
                  if Test_Wrap(msg,p)then
                    ps.state := C_U_A;
                  else
                    ps.state := C_V;
                  endif;
                endif;

            else
                CCErrorUnhandledMsg(msg, p);

          endswitch;

      case C_V:
          switch msg.mtype
              case Inv:
                  if Rec_Inv(msg,p) then
                    ps.state :=  C_I_U;
                  endif;

              case Update:
                  if Rec_Update(msg,p) then
                    if Test_Wrap(msg,p) then
                      ps.state := C_U_A;
                    endif;
                  endif;

              else
                --CCErrorUnhandledMsg(msg, p);
                  return true;

          endswitch;

      case C_V_A:
          switch msg.mtype
              case Inv:
                  if Rec_Inv(msg,p) then
                    ps.state :=  C_V_A_I;
                  endif;

              case Update:
                 if Rec_Update(msg,p) then
                    --if ps.TS = 0 then
                    --  ps.state := C_U_A;
                    --endif;
                 endif;

              case Update_Ack:
                  if Rec_Update_Ack(msg,p) then
                    ps.state := C_V;
                  endif;

              else
                CCErrorUnhandledMsg(msg, p);

          endswitch;

      case C_U_A:
          switch msg.mtype
              case Inv:
                  Send(Inv_N_Ack,msg.src,p,adr,ps.TS,msg.id);

              case Update:
                  if Rec_Update(msg,p) then
                  endif;

              case Wrap:
                  Send(Wrap_Ack,msg.src,p,adr,ps.TS,msg.id);
                  ps.state := C_U_W;

              else
                return false;

          endswitch;

      case C_U_W:
          switch msg.mtype
              case Wrap_Complete:
                  ps.state := C_V;
              else
                return false;

          endswitch;                

      case C_V_A_A:
          switch msg.mtype

              case Update:
                if Rec_Update(msg,p) then
                endif;

              case Inv:
                Send(Inv_N_Ack,msg.src,p,adr,ps.TS,msg.id);

              case Update_Ack:
                  if Rec_Update_Ack(msg,p) then
                    Issue_Wrap(msg,p);
                    ps.state := C_V_W_A;
                  endif;

              else
                return false;

          endswitch;

      case C_V_W_A:
          switch msg.mtype
              case Wrap_Ack:
                if Rec_Wrap_Ack(msg,p) then
                  Issue_Wrap_Complete(msg,p);
                  ps.state := C_V;
                endif          

              else
                CCErrorUnhandledMsg(msg, p);

          endswitch;

      case C_V_A_I:
          switch msg.mtype
              case Inv:
                if Rec_Inv(msg,p) then
                  ps.state :=  C_V_A_I;
                endif;

              case Update:
                  return false;

              case Update_Ack:
                if Rec_Update_Ack(msg,p) then
                  ps.state :=  C_I_U;
                endif;

              else
                CCErrorUnhandledMsg(msg, p);

          endswitch;

      case C_W_A:
          switch msg.mtype
              case Inv:
                  if Rec_Inv(msg,p) then
                    ps.state :=  C_W_I;
                  endif;

              case Inv_Ack:
                  if Rec_Inv_Ack(msg,p) then
                    if ps.TS = 0 then
                      ps.state := C_V_A_A;
                    else
                      ps.state :=  C_V_A; 
                    endif;
                    -- Update global check variable to ensure consistency
                    c_TS[adr]:=ps.TS;                 
                  endif;

              case Inv_N_Ack:
                  if Rec_Inv_N_Ack(msg,p) then
                    ps.state :=  C_I_U;
                  else
                    ps.state :=  C_W_I;
                  endif;

              case Update:
                 return false;
                 --if Rec_Update(msg,p) then
                 --endif;

              else
                  CCErrorUnhandledMsg(msg, p);

          endswitch;

      case C_W_I:
          switch msg.mtype
              case Inv:
                  if Rec_Inv(msg,p) then
                    ps.state :=  C_W_I;
                  endif;

              case Inv_Ack:
                  if Rec_Inv_N_Ack(msg,p) then
                    ps.state :=  C_I_U;
                  endif;

              case Inv_N_Ack:
                  if Rec_Inv_N_Ack(msg,p) then
                    ps.state :=  C_I_U;
                  endif;

              case Update:
                 return false;

              else
                  CCErrorUnhandledMsg(msg, p);  

          endswitch;

      else
        ErrorUnhandledState();

    endswitch;
  endalias;
  endalias;

  --Message processed:
  return true;
end;

-- }}}

--------------------------------------------------------------------------------
-- Rules {{{
--------------------------------------------------------------------------------

-- Processor actions on Caches
ruleset n:Cache do
  ruleset adr:Address do
    alias p:caches[n].CL[adr] do

      -- STATE: C_V ------------------------------------------------------
      rule "I.Write"
        p.state = C_V 
      ==>
        UpdateTS(n, adr);
        Broadcast(Inv, adr, n);
        p.lid:=p.id;
        p.state := C_W_A;
        p.inv_ack := 0;
      endrule;

    endalias;
  endruleset;
endruleset;

-- RECEIVE RULES -----------------------------------------------------
ruleset n:Cache do

  choose midx:net[n] do
    alias chan:net[n] do
    alias msg:chan[midx] do
      rule "Receive unordered"
        !isundefined(chan[midx].mtype) 
      ==>
        if CacheReceive(msg, n) then
          MultiSetRemove(midx, chan);
        endif;

      endrule;
    endalias;
    endalias;
  endchoose;

endruleset;

--------------------------------------------------------------------------------
-- Startstate {{{
--------------------------------------------------------------------------------
startstate
  -- Processor initialization
  for i:Cache do
    for adr:Address do
      caches[i].CL[adr].state := C_V;
      caches[i].CL[adr].TS := 1;
      caches[i].CL[adr].inv_ack:=0;
      caches[i].CL[adr].upd_ack:=0;
      c_TS[adr]:=caches[i].CL[adr].TS;

      wstates[i].CL[adr] := C_I_U;
    endfor;
  endfor;

  AssignCacheID();

  -- Data types to do invariant checking
  for adr: Address do
    c_TS[adr] := 1;
  endfor;

  undefine net;

endstartstate;

-- }}}

--------------------------------------------------------------------------------
-- Invariants {{{
--------------------------------------------------------------------------------

invariant "Cache Consistency Violation"
    forall cc:Cache do
      forall adr:Address do
        (caches[cc].CL[adr].state=C_V)         -- If CL is valid 
        ->                                   -- then
        (caches[cc].CL[adr].TS=c_TS[adr])        -- it also must have most recent TS value
      endforall
    endforall;

invariant "Single-Writer-Multiple-Reader (SWMR)"
    forall adr:Address do
      forall c1:Cache do
      forall c2:Cache do
        ( c1 != c2
        & wstates[c1].CL[adr] = C_V_A )
        ->
        ( wstates[c2].CL[adr] = C_I_U )
      endforall
      endforall
    endforall;

invariant "All Caches invalid"
  ValidEntry()    





-- }}}

