--------------------------------------------------------------------------------
-- Linearization Protocol
--
-- Protocol implemented from transition table by
--  Vasilis Gavrielatos, Antonios Katsarakis
--
-- Verification by
-- N.A. Oswald
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- Constants
--------------------------------------------------------------------------------
const
  -- Number of Processors
  PROC_COUNT: 3;

  -- Cache Line Properties
  ADR_COUNT:   2;   -- Number address (CL)
  VAL_COUNT:   3;   -- Maximum value of TS is 0..VAL_COUNT

  -- Ordered Network Buffer Size
  U_NET_MAX: 2*PROC_COUNT*ADR_COUNT;

--------------------------------------------------------------------------------
-- Types
--------------------------------------------------------------------------------
type
  Cache:      scalarset(PROC_COUNT);   

  Address:    scalarset(ADR_COUNT);

  TSr: 0..VAL_COUNT;
  ids: 0..PROC_COUNT;


  MessageType: enum {     
            Inv,     
            Inv_Ack,     
            Update
            };

  CacheStates: enum {
          C_I_U,
          C_V,
          C_W_A
          };


  Message:
    record
      mtype:  MessageType;
      src:    Cache;
      adr:    Address;
      TS:     TSr;
      id:     ids;
  end;

  CacheLine:
    record
      id:      ids;
      state:   CacheStates;
      TS:      TSr;
      lid:     ids;
      inv_ack: ids;     
  end;

  CacheEntry:
    record
      CL:      array [Address] of CacheLine;
    end;

  WState:
    record
      CL:     array [Address] of CacheStates;
    end;


--------------------------------------------------------------------------------
-- Variables
--------------------------------------------------------------------------------
var
  net:      array [Cache]    of multiset [U_NET_MAX] of Message;
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
      if(caches[i].CL[adr].state = C_V | 
        caches[i].CL[adr].state = C_W_A) then
        valid := true;
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
      Send(Inv_Ack,msg.src,p,msg.adr,ps.TS,Undefined);
      return true;
    endif;
  endalias;

  return false;
end;

function Rec_Inv_Ack(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do
    if ps.TS = msg.TS then

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

function Rec_Update(msg:Message; p:Cache): boolean;
begin
  alias ps:caches[p].CL[msg.adr] do
    if (msg.TS=ps.TS & msg.id=ps.lid) then
      if msg.TS=VAL_COUNT then
        ps.TS:=0;
      endif;
      return true;
    endif;

  endalias;

  return false;
end;

procedure GlobalReset(adr: Address);
var
  count:ids;
begin
    count:=0;

    for i:Cache do
      if caches[i].CL[adr].state = C_V & MultiSetCount(msg:net[i], true) = 0 then
        count := count + 1;
      endif;
    endfor;

    if count=PROC_COUNT then
      for i:Cache do
        caches[i].CL[adr].state := C_V;
        caches[i].CL[adr].TS := 0;
        caches[i].CL[adr].inv_ack := 0;
      endfor;

      c_TS[adr]:=0;

    endif;

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
  alias a:msg.adr do
  alias ps:caches[p].CL[a] do
    switch ps.state

      case C_I_U:
          switch msg.mtype
            case Inv:
                if Rec_Inv(msg,p) then
                endif;

            case Inv_Ack:
                return true;

            case Update:
                if Rec_Update(msg,p) then
                  ps.state :=  C_V;
                endif;

            else
                CCErrorUnhandledMsg(msg, p);

          endswitch;

      case C_V:
          switch msg.mtype
              case Inv:
                  if Rec_Inv(msg,p) then
                    ps.inv_ack:=0;
                    ps.state :=  C_I_U;
                  endif;

              case Inv_Ack:
                  return true;

              case Update:
                  return true;

              else
                  return true;

          endswitch;

      case C_W_A:
          switch msg.mtype
              case Inv:
                  if Rec_Inv(msg,p) then
                    ps.inv_ack:=0;
                    ps.state :=  C_I_U;
                  endif;

              case Inv_Ack:
                  if Rec_Inv_Ack(msg,p) then
                    ps.state :=  C_V; 
                    -- Global TS variable used for model checking
                    c_TS[a]:=ps.TS;                 
                  endif;

              case Update:
                  return true;

              else
                  CCErrorUnhandledMsg(msg, p);

          endswitch;



      else
        ErrorUnhandledState();

    endswitch;
  endalias;
  endalias;

  return true;
end;

-- }}}

--------------------------------------------------------------------------------
-- Rules {{{
--------------------------------------------------------------------------------
ruleset n:Cache do
  ruleset a:Address do
    alias p:caches[n].CL[a] do

      rule "I.Write"
        p.state = C_V 
      ==>
        if p.TS<VAL_COUNT-1 then
          UpdateTS(n, a);
          Broadcast(Inv, a, n);
          p.lid:=p.id;
          p.state := C_W_A;
        else
          GlobalReset(a);
        endif;
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


-- }}}

--------------------------------------------------------------------------------
-- Startstate {{{
--------------------------------------------------------------------------------
startstate

  for i:Cache do
    for a: Address do
    caches[i].CL[a].state := C_V;
    caches[i].CL[a].TS := 0;
    caches[i].CL[a].inv_ack := 0;
    wstates[i].CL[a] := C_I_U;
    endfor;
  endfor;

  AssignCacheID();

  for a: Address do
    c_TS[a] := 0;
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
        (caches[cc].CL[adr].state=C_V)      	 -- If CL is valid 
        ->                            			 -- then
        (caches[cc].CL[adr].TS=c_TS[adr])        -- it also must have most recent TS value
      endforall
    endforall;

invariant "Single-Writer-Multiple-Reader (SWMR)"
    forall adr:Address do
      forall c1:Cache do
      forall c2:Cache do
        ( c1 != c2
        & wstates[c1].CL[adr] = C_W_A )
        ->
        ( wstates[c2].CL[adr] = C_I_U )
      endforall
      endforall
    endforall;
  
invariant "All Caches Invalid"
  ValidEntry()    



-- }}}

