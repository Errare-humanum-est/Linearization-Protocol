/******************************
  Program "VIW.m" compiled by "Caching Murphi Release 5.4.9.1"

  Murphi Last Compiled date: "Jun  2 2017"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9.1"
#define MURPHI_DATE "Jun  2 2017"
#define PROTOCOL_NAME "VIW"
#define BITS_IN_WORLD 2944
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_Cache: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Cache& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Cache& val)
    {
      if (val.defined())
	return ( s << mu_1_Cache::values[ int(val) - 1 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_Cache (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_Cache (void): mu__byte(1, 3, 2) {};
  mu_1_Cache (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Cache& a, mu_1_Cache& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_Cache::values[] =
  { "Cache_1","Cache_2","Cache_3",NULL };

/*** end scalarset declaration ***/
mu_1_Cache mu_1_Cache_undefined_var;

class mu_1_Address: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Address& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Address& val)
    {
      if (val.defined())
	return ( s << mu_1_Address::values[ int(val) - 4 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_Address (const char *name, int os): mu__byte(4, 5, 2, name, os) {};
  mu_1_Address (void): mu__byte(4, 5, 2) {};
  mu_1_Address (int val): mu__byte(4, 5, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -4]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 4] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Address& a, mu_1_Address& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_Address::values[] =
  { "Address_1","Address_2",NULL };

/*** end scalarset declaration ***/
mu_1_Address mu_1_Address_undefined_var;

class mu_1_TSr: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_TSr& val) { return mu__byte::operator=((int) val); };
  mu_1_TSr (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_TSr (void): mu__byte(0, 2, 2) {};
  mu_1_TSr (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_TSr mu_1_TSr_undefined_var;

class mu_1_ids: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_ids& val) { return mu__byte::operator=((int) val); };
  mu_1_ids (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_ids (void): mu__byte(0, 3, 3) {};
  mu_1_ids (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_ids mu_1_ids_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 6] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (const char *name, int os): mu__byte(6, 13, 4, name, os) {};
  mu_1_MessageType (void): mu__byte(6, 13, 4) {};
  mu_1_MessageType (int val): mu__byte(6, 13, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -6]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -6] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_MessageType::values[] = {"Inv","Inv_Ack","Inv_N_Ack","Update","Update_Ack","Wrap","Wrap_Ack","Wrap_Complete",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_CacheStates: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_CacheStates& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_CacheStates& val)
  {
    if (val.defined())
      return ( s << mu_1_CacheStates::values[ int(val) - 14] );
    else return ( s << "Undefined" );
  };

  mu_1_CacheStates (const char *name, int os): mu__byte(14, 23, 4, name, os) {};
  mu_1_CacheStates (void): mu__byte(14, 23, 4) {};
  mu_1_CacheStates (int val): mu__byte(14, 23, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -14]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -14] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_CacheStates::values[] = {"C_I_U","C_V","C_V_A","C_V_A_I","C_W_A","C_W_I","C_V_A_A","C_V_W_A","C_U_A","C_U_W",NULL };

/*** end of enum declaration ***/
mu_1_CacheStates mu_1_CacheStates_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_MessageType mu_mtype;
  mu_1_Cache mu_src;
  mu_1_Address mu_adr;
  mu_1_TSr mu_TS;
  mu_1_ids mu_id;
  mu_1_Message ( const char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
    w = CompareWeight(a.mu_TS, b.mu_TS);
    if (w!=0) return w;
    w = CompareWeight(a.mu_id, b.mu_id);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
    w = Compare(a.mu_TS, b.mu_TS);
    if (w!=0) return w;
    w = Compare(a.mu_id, b.mu_id);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_adr.MultisetSort();
    mu_TS.MultisetSort();
    mu_id.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_adr.print_statistic();
    mu_TS.print_statistic();
    mu_id.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_src.clear();
    mu_adr.clear();
    mu_TS.clear();
    mu_id.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_src.undefine();
    mu_adr.undefine();
    mu_TS.undefine();
    mu_id.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_src.reset();
    mu_adr.reset();
    mu_TS.reset();
    mu_id.reset();
 };
  void print() {
    mu_mtype.print();
    mu_src.print();
    mu_adr.print();
    mu_TS.print();
    mu_id.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_adr.print_diff(prevstate);
    mu_TS.print_diff(prevstate);
    mu_id.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_adr.to_state(thestate);
    mu_TS.to_state(thestate);
    mu_id.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_adr.value(from.mu_adr.value());
    mu_TS.value(from.mu_TS.value());
    mu_id.value(from.mu_id.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_mtype.set_self_2(name, ".mtype", os + 0 ); else mu_mtype.set_self_2(NULL, NULL, 0);
  if (name) mu_src.set_self_2(name, ".src", os + 8 ); else mu_src.set_self_2(NULL, NULL, 0);
  if (name) mu_adr.set_self_2(name, ".adr", os + 16 ); else mu_adr.set_self_2(NULL, NULL, 0);
  if (name) mu_TS.set_self_2(name, ".TS", os + 24 ); else mu_TS.set_self_2(NULL, NULL, 0);
  if (name) mu_id.set_self_2(name, ".id", os + 32 ); else mu_id.set_self_2(NULL, NULL, 0);
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1_CacheLine
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_CacheStates mu_state;
  mu_1_ids mu_id;
  mu_1_TSr mu_TS;
  mu_1_ids mu_lid;
  mu_1_ids mu_inv_ack;
  mu_1_ids mu_upd_ack;
  mu_1_CacheLine ( const char *n, int os ) { set_self(n,os); };
  mu_1_CacheLine ( void ) {};

  virtual ~mu_1_CacheLine(); 
friend int CompareWeight(mu_1_CacheLine& a, mu_1_CacheLine& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_id, b.mu_id);
    if (w!=0) return w;
    w = CompareWeight(a.mu_TS, b.mu_TS);
    if (w!=0) return w;
    w = CompareWeight(a.mu_lid, b.mu_lid);
    if (w!=0) return w;
    w = CompareWeight(a.mu_inv_ack, b.mu_inv_ack);
    if (w!=0) return w;
    w = CompareWeight(a.mu_upd_ack, b.mu_upd_ack);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_CacheLine& a, mu_1_CacheLine& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_id, b.mu_id);
    if (w!=0) return w;
    w = Compare(a.mu_TS, b.mu_TS);
    if (w!=0) return w;
    w = Compare(a.mu_lid, b.mu_lid);
    if (w!=0) return w;
    w = Compare(a.mu_inv_ack, b.mu_inv_ack);
    if (w!=0) return w;
    w = Compare(a.mu_upd_ack, b.mu_upd_ack);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_id.MultisetSort();
    mu_TS.MultisetSort();
    mu_lid.MultisetSort();
    mu_inv_ack.MultisetSort();
    mu_upd_ack.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_id.print_statistic();
    mu_TS.print_statistic();
    mu_lid.print_statistic();
    mu_inv_ack.print_statistic();
    mu_upd_ack.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_id.clear();
    mu_TS.clear();
    mu_lid.clear();
    mu_inv_ack.clear();
    mu_upd_ack.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_id.undefine();
    mu_TS.undefine();
    mu_lid.undefine();
    mu_inv_ack.undefine();
    mu_upd_ack.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_id.reset();
    mu_TS.reset();
    mu_lid.reset();
    mu_inv_ack.reset();
    mu_upd_ack.reset();
 };
  void print() {
    mu_state.print();
    mu_id.print();
    mu_TS.print();
    mu_lid.print();
    mu_inv_ack.print();
    mu_upd_ack.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_id.print_diff(prevstate);
    mu_TS.print_diff(prevstate);
    mu_lid.print_diff(prevstate);
    mu_inv_ack.print_diff(prevstate);
    mu_upd_ack.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_id.to_state(thestate);
    mu_TS.to_state(thestate);
    mu_lid.to_state(thestate);
    mu_inv_ack.to_state(thestate);
    mu_upd_ack.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_CacheLine& operator= (const mu_1_CacheLine& from) {
    mu_state.value(from.mu_state.value());
    mu_id.value(from.mu_id.value());
    mu_TS.value(from.mu_TS.value());
    mu_lid.value(from.mu_lid.value());
    mu_inv_ack.value(from.mu_inv_ack.value());
    mu_upd_ack.value(from.mu_upd_ack.value());
    return *this;
  };
};

  void mu_1_CacheLine::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_CacheLine::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_CacheLine::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_state.set_self_2(name, ".state", os + 0 ); else mu_state.set_self_2(NULL, NULL, 0);
  if (name) mu_id.set_self_2(name, ".id", os + 8 ); else mu_id.set_self_2(NULL, NULL, 0);
  if (name) mu_TS.set_self_2(name, ".TS", os + 16 ); else mu_TS.set_self_2(NULL, NULL, 0);
  if (name) mu_lid.set_self_2(name, ".lid", os + 24 ); else mu_lid.set_self_2(NULL, NULL, 0);
  if (name) mu_inv_ack.set_self_2(name, ".inv_ack", os + 32 ); else mu_inv_ack.set_self_2(NULL, NULL, 0);
  if (name) mu_upd_ack.set_self_2(name, ".upd_ack", os + 40 ); else mu_upd_ack.set_self_2(NULL, NULL, 0);
}

mu_1_CacheLine::~mu_1_CacheLine()
{
}

/*** end record declaration ***/
mu_1_CacheLine mu_1_CacheLine_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_CacheLine array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_0 (const char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_CacheLine& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 4 ) && ( index <= 5 ) )
      return array[ index - 4 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Address is internally represented from 4 to 5.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 4 ];
#endif
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_0::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Address_1", i * 48 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Address_2", i * 48 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1_CacheEntry
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_0 mu_CL;
  mu_1_CacheEntry ( const char *n, int os ) { set_self(n,os); };
  mu_1_CacheEntry ( void ) {};

  virtual ~mu_1_CacheEntry(); 
friend int CompareWeight(mu_1_CacheEntry& a, mu_1_CacheEntry& b)
  {
    int w;
    w = CompareWeight(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_CacheEntry& a, mu_1_CacheEntry& b)
  {
    int w;
    w = Compare(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_CL.MultisetSort();
  }
  void print_statistic()
  {
    mu_CL.print_statistic();
  }
  void clear() {
    mu_CL.clear();
 };
  void undefine() {
    mu_CL.undefine();
 };
  void reset() {
    mu_CL.reset();
 };
  void print() {
    mu_CL.print();
  };
  void print_diff(state *prevstate) {
    mu_CL.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_CL.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_CacheEntry& operator= (const mu_1_CacheEntry& from) {
    mu_CL = from.mu_CL;
    return *this;
  };
};

  void mu_1_CacheEntry::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_CacheEntry::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_CacheEntry::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_CL.set_self_2(name, ".CL", os + 0 ); else mu_CL.set_self_2(NULL, NULL, 0);
}

mu_1_CacheEntry::~mu_1_CacheEntry()
{
}

/*** end record declaration ***/
mu_1_CacheEntry mu_1_CacheEntry_undefined_var;

class mu_1__type_1
{
 public:
  mu_1_CacheStates array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_1 (const char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1_CacheStates& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 4 ) && ( index <= 5 ) )
      return array[ index - 4 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Address is internally represented from 4 to 5.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 4 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Address_1", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Address_2", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1_WState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_1 mu_CL;
  mu_1_WState ( const char *n, int os ) { set_self(n,os); };
  mu_1_WState ( void ) {};

  virtual ~mu_1_WState(); 
friend int CompareWeight(mu_1_WState& a, mu_1_WState& b)
  {
    int w;
    w = CompareWeight(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_WState& a, mu_1_WState& b)
  {
    int w;
    w = Compare(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_CL.MultisetSort();
  }
  void print_statistic()
  {
    mu_CL.print_statistic();
  }
  void clear() {
    mu_CL.clear();
 };
  void undefine() {
    mu_CL.undefine();
 };
  void reset() {
    mu_CL.reset();
 };
  void print() {
    mu_CL.print();
  };
  void print_diff(state *prevstate) {
    mu_CL.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_CL.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_WState& operator= (const mu_1_WState& from) {
    mu_CL = from.mu_CL;
    return *this;
  };
};

  void mu_1_WState::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_WState::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_WState::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_CL.set_self_2(name, ".CL", os + 0 ); else mu_CL.set_self_2(NULL, NULL, 0);
}

mu_1_WState::~mu_1_WState()
{
}

/*** end record declaration ***/
mu_1_WState mu_1_WState_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_2_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_2_id () : mu__byte(0,17,0) {};
  mu_1__type_2_id (int val) : mu__byte(0,17,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_2
{
 public:
  mu_1_Message array[ 18 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 18 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_2 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_2 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 17) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 18; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<18; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 18; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 18; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 18; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 18; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 18; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 18; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_2_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 18; i++)
      if (valid[i].value())
	array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
	 << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 18; i++)
      {
	StateCopy(workingstate, prevstate);
	prevvalid = valid[i].value();
	StateCopy(workingstate, &temp);
	if (prevvalid && !valid[i].value())
	  array[i].print();
	if (!prevvalid && valid[i].value())
	  array[i].print();
	if (prevvalid && valid[i].value())
	  array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 18) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 18; i++)
      if (!valid[i].value())
	{
	  array[i] = element;
	  valid[i].value(TRUE);
	  break;
	}
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_2_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 18; i++)
      if (valid[i].value())
	{
	  if (j!=i)
	    array[j++] = array[i];
	  else
	    j++;
	}
    if (j != current_size) current_size = j;
    for (i = j; i < 18; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 18; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
	if (Compare(array[i],array[j])>0)
	  {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	  }
  }
};

  void mu_1__type_2::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self( const char *n, int os)
{
  int i,k;
  name = (char *)n;
  for(i = 0; i < 18; i++)
    if (n) array[i].set_self(tsprintf("%s{%d}", n,i), i * 40 + os); else array[i].set_self(NULL, 0);
  k = os + i * 40;
  for(i = 0; i < 18; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end multiset declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1__type_2 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_3 (const char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1__type_2& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Cache is internally represented from 1 to 3.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Cache_1", i * 864 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Cache_2", i * 864 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Cache_3", i * 864 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4
{
 public:
  mu_1_CacheEntry array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_4 (const char *n, int os) { set_self(n, os); };
  mu_1__type_4 ( void ) {};
  virtual ~mu_1__type_4 ();
  mu_1_CacheEntry& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Cache is internally represented from 1 to 3.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_4::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Cache_1", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Cache_2", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Cache_3", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  mu_1_WState array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_5 (const char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1_WState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Cache is internally represented from 1 to 3.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_5::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Cache_1", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Cache_2", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Cache_3", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6
{
 public:
  mu_1_TSr array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_6 (const char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1_TSr& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 4 ) && ( index <= 5 ) )
      return array[ index - 4 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Address is internally represented from 4 to 5.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 4 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_6::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Address_1", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Address_2", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

const int mu_PROC_COUNT = 3;
const int mu_ADR_COUNT = 2;
const int mu_VAL_COUNT = 2;
const int mu_U_NET_MAX = 18;
const int mu_Cache_1 = 1;
const int mu_Cache_2 = 2;
const int mu_Cache_3 = 3;
const int mu_Address_1 = 4;
const int mu_Address_2 = 5;
const int mu_Inv = 6;
const int mu_Inv_Ack = 7;
const int mu_Inv_N_Ack = 8;
const int mu_Update = 9;
const int mu_Update_Ack = 10;
const int mu_Wrap = 11;
const int mu_Wrap_Ack = 12;
const int mu_Wrap_Complete = 13;
const int mu_C_I_U = 14;
const int mu_C_V = 15;
const int mu_C_V_A = 16;
const int mu_C_V_A_I = 17;
const int mu_C_W_A = 18;
const int mu_C_W_I = 19;
const int mu_C_V_A_A = 20;
const int mu_C_V_W_A = 21;
const int mu_C_U_A = 22;
const int mu_C_U_W = 23;
/*** Variable declaration ***/
mu_1__type_3 mu_net("net",0);

/*** Variable declaration ***/
mu_1__type_4 mu_caches("caches",2592);

/*** Variable declaration ***/
mu_1__type_5 mu_wstates("wstates",2880);

/*** Variable declaration ***/
mu_1__type_6 mu_c_TS("c_TS",2928);

mu_0_boolean mu_ValidEntry()
{
/*** Variable declaration ***/
mu_0_boolean mu_valid("valid",0);

mu_valid = mu_false;
{
for(int mu_adr = 4; mu_adr <= 5; mu_adr++) {
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
bool mu__boolexpr7;
bool mu__boolexpr8;
bool mu__boolexpr9;
bool mu__boolexpr10;
  if ((mu_caches[mu_i].mu_CL[mu_adr].mu_state) == (mu_C_V_A)) mu__boolexpr10 = TRUE ;
  else {
  mu__boolexpr10 = ((mu_caches[mu_i].mu_CL[mu_adr].mu_state) == (mu_C_V)) ; 
}
  if (mu__boolexpr10) mu__boolexpr9 = TRUE ;
  else {
  mu__boolexpr9 = ((mu_caches[mu_i].mu_CL[mu_adr].mu_state) == (mu_C_W_A)) ; 
}
  if (mu__boolexpr9) mu__boolexpr8 = TRUE ;
  else {
  mu__boolexpr8 = ((mu_caches[mu_i].mu_CL[mu_adr].mu_state) == (mu_C_V_A_A)) ; 
}
  if (mu__boolexpr8) mu__boolexpr7 = TRUE ;
  else {
  mu__boolexpr7 = ((mu_caches[mu_i].mu_CL[mu_adr].mu_state) == (mu_C_V_W_A)) ; 
}
if ( mu__boolexpr7 )
{
mu_valid = mu_true;
}
};
};
};
};
return mu_valid;
	Error.Error("The end of function ValidEntry reached without returning values.");
};
/*** end function declaration ***/

void mu_Send(const mu_1_MessageType& mu_mtype, const mu_1_Cache& mu_dst, const mu_1_Cache& mu_src, const mu_1_Address& mu_adr, const mu_1_TSr& mu_TS, const mu_1_ids& mu_id)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_TS.isundefined())
  mu_msg.mu_TS.undefine();
else
  mu_msg.mu_TS = mu_TS;
if (mu_id.isundefined())
  mu_msg.mu_id.undefine();
else
  mu_msg.mu_id = mu_id;
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr11 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_net[mu_dst].valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr11++;
	}
      if (mu_i == 18-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr11) < (mu_U_NET_MAX)) ) Error.Error("Assertion failed: Too many messages");
mu_net[mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_Broadcast(const mu_1_MessageType& mu_mtype, const mu_1_Address& mu_adr, const mu_1_Cache& mu_p)
{
{
for(int mu_cc = 1; mu_cc <= 3; mu_cc++) {
if ( (mu_cc) != (mu_p) )
{
mu_Send ( mu_mtype, mu_cc, mu_p, mu_adr, mu_caches[mu_p].mu_CL[mu_adr].mu_TS, mu_caches[mu_p].mu_CL[mu_adr].mu_id );
}
};
};
};
/*** end procedure declaration ***/

void mu_AssignCacheID()
{
/*** Variable declaration ***/
mu_1_ids mu_id("id",0);

mu_id = 0;
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_id = (mu_id) + (1);
{
for(int mu_adr = 4; mu_adr <= 5; mu_adr++) {
if (mu_id.isundefined())
  mu_caches[mu_i].mu_CL[mu_adr].mu_id.undefine();
else
  mu_caches[mu_i].mu_CL[mu_adr].mu_id = mu_id;
if (mu_id.isundefined())
  mu_caches[mu_i].mu_CL[mu_adr].mu_lid.undefine();
else
  mu_caches[mu_i].mu_CL[mu_adr].mu_lid = mu_id;
};
};
};
};
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledMsg()
{
Error.Error("Error: Unhandled message type!");
};
/*** end procedure declaration ***/

void mu_CCErrorUnhandledMsg(mu_1_Message& mu_msg, const mu_1_Cache& mu_p)
{
cout << "\n";
cout << "ERROR TRACE TERMINAL STATE \n";
cout << "Error State: ";
mu_caches[mu_p].mu_CL[mu_msg.mu_adr].mu_state.print();
cout << "Message Type: ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
cout << "Message Source: ";
cout << ( mu_msg.mu_src );
cout << "\n\n";
Error.Error("Error: Unhandled message type!");
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledState()
{
Error.Error("Error: Unhandled state!");
};
/*** end procedure declaration ***/

mu_0_boolean mu_Rec_Inv(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
bool mu__boolexpr12;
  if ((mu_msg.mu_TS) > (mu_ps.mu_TS)) mu__boolexpr12 = TRUE ;
  else {
bool mu__boolexpr13;
  if (!((mu_msg.mu_TS) == (mu_ps.mu_TS))) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_msg.mu_id) > (mu_ps.mu_lid)) ; 
}
  mu__boolexpr12 = (mu__boolexpr13) ; 
}
if ( mu__boolexpr12 )
{
mu_ps.mu_TS = mu_msg.mu_TS;
mu_ps.mu_lid = mu_msg.mu_id;
mu_Send ( mu_Inv_Ack, mu_msg.mu_src, mu_p, mu_msg.mu_adr, mu_ps.mu_TS, mu_msg.mu_id );
return mu_true;
}
else
{
mu_Send ( mu_Inv_N_Ack, mu_msg.mu_src, mu_p, mu_msg.mu_adr, mu_ps.mu_TS, mu_msg.mu_id );
}
}
return mu_false;
	Error.Error("The end of function Rec_Inv reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_Rec_Inv_Ack(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
bool mu__boolexpr14;
  if (!((mu_msg.mu_TS) == (mu_ps.mu_TS))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_msg.mu_id) == (mu_ps.mu_id)) ; 
}
if ( mu__boolexpr14 )
{
mu_ps.mu_inv_ack = (mu_ps.mu_inv_ack) + (1);
if ( (mu_ps.mu_inv_ack) == (2) )
{
mu_Broadcast ( mu_Update, mu_msg.mu_adr, mu_p );
if ( (mu_msg.mu_TS) == (mu_VAL_COUNT) )
{
mu_ps.mu_TS = 0;
}
mu_ps.mu_inv_ack = 0;
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_wstates[mu_i].mu_CL[mu_msg.mu_adr] = mu_caches[mu_i].mu_CL[mu_msg.mu_adr].mu_state;
};
};
return mu_true;
}
}
}
return mu_false;
	Error.Error("The end of function Rec_Inv_Ack reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_Rec_Inv_N_Ack(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
mu_ps.mu_inv_ack = (mu_ps.mu_inv_ack) + (1);
if ( (mu_ps.mu_inv_ack) == (2) )
{
return mu_true;
}
}
return mu_false;
	Error.Error("The end of function Rec_Inv_N_Ack reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_Rec_Update(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
mu_Send ( mu_Update_Ack, mu_msg.mu_src, mu_p, mu_msg.mu_adr, mu_ps.mu_TS, mu_msg.mu_id );
if ( (mu_msg.mu_TS) == (mu_ps.mu_TS) )
{
if ( (mu_msg.mu_TS) == (mu_VAL_COUNT) )
{
mu_ps.mu_TS = 0;
}
return mu_true;
}
}
return mu_false;
	Error.Error("The end of function Rec_Update reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_Rec_Update_Ack(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
mu_ps.mu_upd_ack = (mu_ps.mu_upd_ack) + (1);
if ( (mu_ps.mu_upd_ack) == (2) )
{
mu_ps.mu_upd_ack = 0;
return mu_true;
}
}
return mu_false;
	Error.Error("The end of function Rec_Update_Ack reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_Rec_Wrap_Ack(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
mu_ps.mu_upd_ack = (mu_ps.mu_upd_ack) + (1);
if ( (mu_ps.mu_upd_ack) == (2) )
{
mu_ps.mu_upd_ack = 0;
return mu_true;
}
}
return mu_false;
	Error.Error("The end of function Rec_Wrap_Ack reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_Test_Wrap(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
if ( (mu_ps.mu_TS) == (0) )
{
return mu_true;
}
}
return mu_false;
	Error.Error("The end of function Test_Wrap reached without returning values.");
};
/*** end function declaration ***/

void mu_Issue_Wrap(mu_1_Message& mu_msg, const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
mu_Broadcast ( mu_Wrap, mu_msg.mu_adr, mu_p );
}
};
/*** end procedure declaration ***/

void mu_Issue_Wrap_Complete(mu_1_Message& mu_msg, const mu_1_Cache& mu_p)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_msg.mu_adr];
mu_Broadcast ( mu_Wrap_Complete, mu_msg.mu_adr, mu_p );
}
};
/*** end procedure declaration ***/

void mu_UpdateTS(const mu_1_Cache& mu_p, const mu_1_Address& mu_adr)
{
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_adr];
if ( (mu_ps.mu_TS) < (mu_VAL_COUNT) )
{
mu_ps.mu_TS = (mu_ps.mu_TS) + (1);
}
else
{
mu_ps.mu_TS = 0;
}
}
};
/*** end procedure declaration ***/

mu_0_boolean mu_CacheReceive(mu_1_Message& mu_msg,const mu_1_Cache& mu_p)
{
{
  const int mu_adr = mu_msg.mu_adr;
{
  mu_1_CacheLine& mu_ps = mu_caches[mu_p].mu_CL[mu_adr];
switch ((int) mu_ps.mu_state) {
case mu_C_I_U:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
if ( mu_Rec_Inv( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_I_U;
}
break;
case mu_Inv_Ack:
return mu_true;
break;
case mu_Update:
if ( mu_Rec_Update( mu_msg, mu_p ) )
{
if ( mu_Test_Wrap( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_U_A;
}
else
{
mu_ps.mu_state = mu_C_V;
}
}
break;
default:
mu_CCErrorUnhandledMsg ( mu_msg, mu_p );
break;
}
break;
case mu_C_V:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
if ( mu_Rec_Inv( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_I_U;
}
break;
case mu_Update:
if ( mu_Rec_Update( mu_msg, mu_p ) )
{
if ( mu_Test_Wrap( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_U_A;
}
}
break;
default:
return mu_true;
break;
}
break;
case mu_C_V_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
if ( mu_Rec_Inv( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_V_A_I;
}
break;
case mu_Update:
if ( mu_Rec_Update( mu_msg, mu_p ) )
{
}
break;
case mu_Update_Ack:
if ( mu_Rec_Update_Ack( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_V;
}
break;
default:
mu_CCErrorUnhandledMsg ( mu_msg, mu_p );
break;
}
break;
case mu_C_U_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_Send ( mu_Inv_N_Ack, mu_msg.mu_src, mu_p, mu_adr, mu_ps.mu_TS, mu_msg.mu_id );
break;
case mu_Update:
if ( mu_Rec_Update( mu_msg, mu_p ) )
{
}
break;
case mu_Wrap:
mu_Send ( mu_Wrap_Ack, mu_msg.mu_src, mu_p, mu_adr, mu_ps.mu_TS, mu_msg.mu_id );
mu_ps.mu_state = mu_C_U_W;
break;
default:
return mu_false;
break;
}
break;
case mu_C_U_W:
switch ((int) mu_msg.mu_mtype) {
case mu_Wrap_Complete:
mu_ps.mu_state = mu_C_V;
break;
default:
return mu_false;
break;
}
break;
case mu_C_V_A_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Update:
if ( mu_Rec_Update( mu_msg, mu_p ) )
{
}
break;
case mu_Inv:
mu_Send ( mu_Inv_N_Ack, mu_msg.mu_src, mu_p, mu_adr, mu_ps.mu_TS, mu_msg.mu_id );
break;
case mu_Update_Ack:
if ( mu_Rec_Update_Ack( mu_msg, mu_p ) )
{
mu_Issue_Wrap ( mu_msg, mu_p );
mu_ps.mu_state = mu_C_V_W_A;
}
break;
default:
return mu_false;
break;
}
break;
case mu_C_V_W_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Wrap_Ack:
if ( mu_Rec_Wrap_Ack( mu_msg, mu_p ) )
{
mu_Issue_Wrap_Complete ( mu_msg, mu_p );
mu_ps.mu_state = mu_C_V;
}
break;
default:
mu_CCErrorUnhandledMsg ( mu_msg, mu_p );
break;
}
break;
case mu_C_V_A_I:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
if ( mu_Rec_Inv( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_V_A_I;
}
break;
case mu_Update:
return mu_false;
break;
case mu_Update_Ack:
if ( mu_Rec_Update_Ack( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_I_U;
}
break;
default:
mu_CCErrorUnhandledMsg ( mu_msg, mu_p );
break;
}
break;
case mu_C_W_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
if ( mu_Rec_Inv( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_W_I;
}
break;
case mu_Inv_Ack:
if ( mu_Rec_Inv_Ack( mu_msg, mu_p ) )
{
if ( (mu_ps.mu_TS) == (0) )
{
mu_ps.mu_state = mu_C_V_A_A;
}
else
{
mu_ps.mu_state = mu_C_V_A;
}
mu_c_TS[mu_adr] = mu_ps.mu_TS;
}
break;
case mu_Inv_N_Ack:
if ( mu_Rec_Inv_N_Ack( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_I_U;
}
else
{
mu_ps.mu_state = mu_C_W_I;
}
break;
case mu_Update:
return mu_false;
break;
default:
mu_CCErrorUnhandledMsg ( mu_msg, mu_p );
break;
}
break;
case mu_C_W_I:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
if ( mu_Rec_Inv( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_W_I;
}
break;
case mu_Inv_Ack:
if ( mu_Rec_Inv_N_Ack( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_I_U;
}
break;
case mu_Inv_N_Ack:
if ( mu_Rec_Inv_N_Ack( mu_msg, mu_p ) )
{
mu_ps.mu_state = mu_C_I_U;
}
break;
case mu_Update:
return mu_false;
break;
default:
mu_CCErrorUnhandledMsg ( mu_msg, mu_p );
break;
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
}
}
return mu_true;
	Error.Error("The end of function CacheReceive reached without returning values.");
};
/*** end function declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_net.clear();
  mu_caches.clear();
  mu_wstates.clear();
  mu_c_TS.clear();
}
void world_class::undefine()
{
  mu_net.undefine();
  mu_caches.undefine();
  mu_wstates.undefine();
  mu_c_TS.undefine();
}
void world_class::reset()
{
  mu_net.reset();
  mu_caches.reset();
  mu_wstates.reset();
  mu_c_TS.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_net.print();
  mu_caches.print();
  mu_wstates.print();
  mu_c_TS.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_net.print_statistic();
  mu_caches.print_statistic();
  mu_wstates.print_statistic();
  mu_c_TS.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_net.print_diff(prevstate);
    mu_caches.print_diff(prevstate);
    mu_wstates.print_diff(prevstate);
    mu_c_TS.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_net.to_state( newstate );
  mu_caches.to_state( newstate );
  mu_wstates.to_state( newstate );
  mu_c_TS.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 18) + 0);
    r = r / 18;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("Receive unordered, midx:%s, n:%s", mu_midx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 18) + 0);
    r = r / 18;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  if (!mu_net[mu_n].in(mu_midx)) { return FALSE; }
  mu_1__type_2& mu_chan = mu_net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
    return !(mu_chan[mu_midx].mu_mtype.isundefined());
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 18) + 0);
    r = r / 18;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 54 && mu_midx.value()<18 )
      {
	if ( ( TRUE && mu_net[mu_n].in(mu_midx) ) ) {
  mu_1__type_2& mu_chan = mu_net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
	      if (!(mu_chan[mu_midx].mu_mtype.isundefined())) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    mu_midx.value((r % 18) + 0);
    r = r / 18;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 18) + 0);
    r = r / 18;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1__type_2& mu_chan = mu_net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
if ( mu_CacheReceive( mu_msg, mu_n ) )
{
mu_chan.multisetremove(mu_midx);
}
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("I.Write, adr:%s, n:%s", mu_adr.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_CacheLine& mu_p = mu_caches[mu_n].mu_CL[mu_adr];
    return (mu_p.mu_state) == (mu_C_V);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 54;
    static mu_1_Address mu_adr;
    mu_adr.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 60 )
      {
	if ( ( TRUE  ) ) {
  mu_1_CacheLine& mu_p = mu_caches[mu_n].mu_CL[mu_adr];
	      if ((mu_p.mu_state) == (mu_C_V)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 54;
    mu_adr.value((r % 2) + 4);
    r = r / 2;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Cache mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_CacheLine& mu_p = mu_caches[mu_n].mu_CL[mu_adr];
mu_UpdateTS ( mu_n, mu_adr );
mu_Broadcast ( mu_Inv, mu_adr, mu_n );
mu_p.mu_lid = mu_p.mu_id;
mu_p.mu_state = mu_C_W_A;
mu_p.mu_inv_ack = 0;
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<54)
    { R0.NextRule(what_rule);
      if (what_rule<54) return; }
  if (what_rule>=54 && what_rule<60)
    { R1.NextRule(what_rule);
      if (what_rule<60) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=53) return R0.Condition(r-0);
  if (r>=54 && r<=59) return R1.Condition(r-54);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=53) { R0.Code(r-0); return; } 
  if (r>=54 && r<=59) { R1.Code(r-54); return; } 
}
int Priority(unsigned short r)
{
  if (r<=53) { return R0.Priority(); } 
  if (r>=54 && r<=59) { return R1.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=53) return R0.Name(r-0);
  if (r>=54 && r<=59) return R1.Name(r-54);
  return NULL;
}
};
const unsigned numrules = 60;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 60


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
{
for(int mu_adr = 4; mu_adr <= 5; mu_adr++) {
mu_caches[mu_i].mu_CL[mu_adr].mu_state = mu_C_V;
mu_caches[mu_i].mu_CL[mu_adr].mu_TS = 1;
mu_caches[mu_i].mu_CL[mu_adr].mu_inv_ack = 0;
mu_caches[mu_i].mu_CL[mu_adr].mu_upd_ack = 0;
mu_c_TS[mu_adr] = mu_caches[mu_i].mu_CL[mu_adr].mu_TS;
mu_wstates[mu_i].mu_CL[mu_adr] = mu_C_I_U;
};
};
};
};
mu_AssignCacheID (  );
{
for(int mu_adr = 4; mu_adr <= 5; mu_adr++) {
mu_c_TS[mu_adr] = 1;
};
};
mu_net.undefine();
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_15() // Invariant "All Caches invalid"
{
return mu_ValidEntry(  );
};

bool mu__condition_16() // Condition for Rule "All Caches invalid"
{
  return mu__invariant_15( );
}

/**** end rule declaration ****/

int mu__invariant_17() // Invariant "Single-Writer-Multiple-Reader (SWMR)"
{
bool mu__quant18; 
mu__quant18 = TRUE;
{
for(int mu_adr = 4; mu_adr <= 5; mu_adr++) {
bool mu__quant19; 
mu__quant19 = TRUE;
{
for(int mu_c1 = 1; mu_c1 <= 3; mu_c1++) {
bool mu__quant20; 
mu__quant20 = TRUE;
{
for(int mu_c2 = 1; mu_c2 <= 3; mu_c2++) {
bool mu__boolexpr21;
bool mu__boolexpr22;
  if (!((mu_c1) != (mu_c2))) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_wstates[mu_c1].mu_CL[mu_adr]) == (mu_C_V_A)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = TRUE ;
  else {
  mu__boolexpr21 = ((mu_wstates[mu_c2].mu_CL[mu_adr]) == (mu_C_I_U)) ; 
}
if ( !(mu__boolexpr21) )
  { mu__quant20 = FALSE; break; }
};
};
if ( !(mu__quant20) )
  { mu__quant19 = FALSE; break; }
};
};
if ( !(mu__quant19) )
  { mu__quant18 = FALSE; break; }
};
};
return mu__quant18;
};

bool mu__condition_23() // Condition for Rule "Single-Writer-Multiple-Reader (SWMR)"
{
  return mu__invariant_17( );
}

/**** end rule declaration ****/

int mu__invariant_24() // Invariant "Cache Consistency Violation"
{
bool mu__quant25; 
mu__quant25 = TRUE;
{
for(int mu_cc = 1; mu_cc <= 3; mu_cc++) {
bool mu__quant26; 
mu__quant26 = TRUE;
{
for(int mu_adr = 4; mu_adr <= 5; mu_adr++) {
bool mu__boolexpr27;
  if (!((mu_caches[mu_cc].mu_CL[mu_adr].mu_state) == (mu_C_V))) mu__boolexpr27 = TRUE ;
  else {
  mu__boolexpr27 = ((mu_caches[mu_cc].mu_CL[mu_adr].mu_TS) == (mu_c_TS[mu_adr])) ; 
}
if ( !(mu__boolexpr27) )
  { mu__quant26 = FALSE; break; }
};
};
if ( !(mu__quant26) )
  { mu__quant25 = FALSE; break; }
};
};
return mu__quant25;
};

bool mu__condition_28() // Condition for Rule "Cache Consistency Violation"
{
  return mu__invariant_24( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Cache Consistency Violation", &mu__condition_28, NULL, },
{"Single-Writer-Multiple-Reader (SWMR)", &mu__condition_23, NULL, },
{"All Caches invalid", &mu__condition_16, NULL, },
};
const unsigned short numinvariants = 3;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
c_TS:ScalarsetArrayOfFree
net:Complex
caches:Complex
wstates:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_Address[2];
  int undefined_class_mu_1_Address;// has the highest class number

  void Print_class_mu_1_Address();
  bool OnlyOneRemain_mu_1_Address;
  bool MTO_class_mu_1_Address()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Address)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Address[i]== class_mu_1_Address[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Address = TRUE;
    return FALSE;
  }
  int class_mu_1_Cache[3];
  int undefined_class_mu_1_Cache;// has the highest class number

  void Print_class_mu_1_Cache();
  bool OnlyOneRemain_mu_1_Cache;
  bool MTO_class_mu_1_Cache()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Cache)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Cache[i]== class_mu_1_Cache[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Cache = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_Address;
  typedef int arr_mu_1_Address[2];
  arr_mu_1_Address * perm_mu_1_Address;
  arr_mu_1_Address * revperm_mu_1_Address;

  int size_mu_1_Address[2];
  bool reversed_sorted_mu_1_Address(int start, int end);
  void reverse_reversed_mu_1_Address(int start, int end);

  int * in_mu_1_Cache;
  typedef int arr_mu_1_Cache[3];
  arr_mu_1_Cache * perm_mu_1_Cache;
  arr_mu_1_Cache * revperm_mu_1_Cache;

  int size_mu_1_Cache[3];
  bool reversed_sorted_mu_1_Cache(int start, int end);
  void reverse_reversed_mu_1_Cache(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Address* perm, int size, mu_1_Address k);
  void GenPerm0(mu_1_Address* perm, int size, unsigned long& index);

  bool ok1(mu_1_Cache* perm, int size, mu_1_Cache k);
  void GenPerm1(mu_1_Cache* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Address()
{
  cout << "class_mu_1_Address:\t";
  for (int i=0; i<2; i++)
    cout << class_mu_1_Address[i];
  cout << " " << undefined_class_mu_1_Address << "\n";
}
void PermSet::Print_class_mu_1_Cache()
{
  cout << "class_mu_1_Cache:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_Cache[i];
  cout << " " << undefined_class_mu_1_Cache << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Address[i]== class_mu_1_Address[j])
	    return TRUE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Cache[i]== class_mu_1_Cache[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_Address Perm0[2];
    mu_1_Cache Perm1[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[12];
 in_mu_1_Address = new int[12];
 perm_mu_1_Address = new arr_mu_1_Address[2];
 revperm_mu_1_Address = new arr_mu_1_Address[2];
 in_mu_1_Cache = new int[12];
 perm_mu_1_Cache = new arr_mu_1_Cache[6];
 revperm_mu_1_Cache = new arr_mu_1_Cache[6];

    // Set perm and revperm
    count = 0;
    for (i=4; i<=5; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=4; j<=5; j++)
        for (k=4; k<=5; k++)
          if (revperm_mu_1_Address[i][k-4]==j)   // k - base 
            perm_mu_1_Address[i][j-4]=k; // j - base 
    count = 0;
    for (i=1; i<=3; i++)
      {
        Perm1[0].value(i);
        GenPerm1(Perm1, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=1; j<=3; j++)
        for (k=1; k<=3; k++)
          if (revperm_mu_1_Cache[i][k-1]==j)   // k - base 
            perm_mu_1_Cache[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Address = 0;
    int i_mu_1_Cache = 0;
    size = 12;
    count = 12;
    for (i=0; i<12; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Address[i] = i_mu_1_Address;
      i_mu_1_Address += carry;
      if (i_mu_1_Address >= 2) { i_mu_1_Address = 0; carry = 1; } 
      else { carry = 0; } 
      in_mu_1_Cache[i] = i_mu_1_Cache;
      i_mu_1_Cache += carry;
      if (i_mu_1_Cache >= 6) { i_mu_1_Cache = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Address = new int[1];
 perm_mu_1_Address = new arr_mu_1_Address[1];
 revperm_mu_1_Address = new arr_mu_1_Address[1];
 in_mu_1_Cache = new int[1];
 perm_mu_1_Cache = new arr_mu_1_Cache[1];
 revperm_mu_1_Cache = new arr_mu_1_Cache[1];
  in[0] = TRUE;
    in_mu_1_Address[0] = 0;
    in_mu_1_Cache[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<2; i++)
    class_mu_1_Address[i]=0;
  undefined_class_mu_1_Address=0;
  OnlyOneRemain_mu_1_Address = FALSE;
  for (i=0; i<3; i++)
    class_mu_1_Cache[i]=0;
  undefined_class_mu_1_Cache=0;
  OnlyOneRemain_mu_1_Cache = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<12; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Address[2];
  int size_mu_1_Address[2];
  bool should_be_in_mu_1_Address[2];
  int start_mu_1_Cache[3];
  int size_mu_1_Cache[3];
  bool should_be_in_mu_1_Cache[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Address; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Address[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Address[k]==j)
	  {
	    size_mu_1_Address[k] = class_size;
	    start_mu_1_Address[k] = start;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Cache; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Cache[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Cache[k]==j)
	  {
	    size_mu_1_Cache[k] = class_size;
	    start_mu_1_Cache[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_Address[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Address[i][k]-4 >=start_mu_1_Address[k] 
	     && perm_mu_1_Address[i][k]-4 < start_mu_1_Address[k] + size_mu_1_Address[k]) )
  	    {
	      should_be_in_mu_1_Address[i] = FALSE;
	      break;
	    }
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_Cache[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Cache[i][k]-1 >=start_mu_1_Cache[k] 
	     && perm_mu_1_Cache[i][k]-1 < start_mu_1_Cache[k] + size_mu_1_Cache[k]) )
  	    {
	      should_be_in_mu_1_Cache[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<12; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Address[in_mu_1_Address[i]]) in[i] = FALSE;
      if (in[i] && !should_be_in_mu_1_Cache[in_mu_1_Cache[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Address; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Address[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Address[k]==j)
	  {
	    size_mu_1_Address[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Cache; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Cache[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Cache[k]==j)
	  {
	    size_mu_1_Cache[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Address; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Address[k]==j)
	      revperm_mu_1_Address[0][start++] = k+4;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Address[0][k]==j+4)
        perm_mu_1_Address[0][j]=k+4;
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Cache; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Cache[k]==j)
	      revperm_mu_1_Cache[0][start++] = k+1;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Cache[0][k]==j+1)
        perm_mu_1_Cache[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Address* Perm, int size, mu_1_Address k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Address* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=2)
    {
      for (i=4; i<=5; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=4; i<=5; i++)
        revperm_mu_1_Address[count][i-4]=Perm[i-4].value();// i - base
      count++;
    }
}
bool PermSet::ok1(mu_1_Cache* Perm, int size, mu_1_Cache k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm1(mu_1_Cache* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=1; i<=3; i++)
        if(ok1(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm1(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=3; i++)
        revperm_mu_1_Cache[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Address(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Address[0][i]<revperm_mu_1_Address[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Address(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Address[0][j];
      revperm_mu_1_Address[0][j] = revperm_mu_1_Address[0][i];
      revperm_mu_1_Address[0][i] = temp;
    }
}
bool PermSet::reversed_sorted_mu_1_Cache(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Cache[0][i]<revperm_mu_1_Cache[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Cache(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Cache[0][j];
      revperm_mu_1_Cache[0][j] = revperm_mu_1_Cache[0][i];
      revperm_mu_1_Cache[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 2; )
    {
      end = start-1+size_mu_1_Address[revperm_mu_1_Address[0][start]-4];
      if (reversed_sorted_mu_1_Address(start,end))
	       {
	  reverse_reversed_mu_1_Address(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Address(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Address[0][j]<revperm_mu_1_Address[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Address[0][j];
			  revperm_mu_1_Address[0][j] = revperm_mu_1_Address[0][k];
			  revperm_mu_1_Address[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Address(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) {
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_Cache[revperm_mu_1_Cache[0][start]-1];
      if (reversed_sorted_mu_1_Cache(start,end))
	       {
	  reverse_reversed_mu_1_Cache(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Cache(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Cache[0][j]<revperm_mu_1_Cache[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Cache[0][j];
			  revperm_mu_1_Cache[0][j] = revperm_mu_1_Cache[0][k];
			  revperm_mu_1_Cache[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Cache(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
}
if (!nexted) return FALSE;
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Address[0][k]==j+4)   // k - base 
	perm_mu_1_Address[0][j]=k+4; // j - base 
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Cache[0][k]==j+1)   // k - base 
	perm_mu_1_Cache[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_c_TS.MultisetSort();
        mu_net.MultisetSort();
        mu_caches.MultisetSort();
        mu_wstates.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Cache::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Cache[Perm.in_mu_1_Cache[i]][value()-1]); // value - base
};
void mu_1_Cache::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Cache[value()-1]==Perm.undefined_class_mu_1_Cache) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Cache[i] == Perm.undefined_class_mu_1_Cache && i!=value()-1)
            Perm.class_mu_1_Cache[i]++;
        value(1 + Perm.undefined_class_mu_1_Cache++);
      }
    else 
      {
        value(Perm.class_mu_1_Cache[value()-1]+1);
      }
}
void mu_1_Cache::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Cache::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Cache[value()-1]==Perm.undefined_class_mu_1_Cache) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Cache[i] == Perm.undefined_class_mu_1_Cache && i!=value()-1)
            Perm.class_mu_1_Cache[i]++;
        Perm.undefined_class_mu_1_Cache++;
      }
}
void mu_1_Cache::ArrayLimit(PermSet& Perm) {}
void mu_1_Cache::Limit(PermSet& Perm) {}
void mu_1_Cache::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Address::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Address[Perm.in_mu_1_Address[i]][value()-4]); // value - base
};
void mu_1_Address::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Address[value()-4]==Perm.undefined_class_mu_1_Address) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Address[i] == Perm.undefined_class_mu_1_Address && i!=value()-4)
            Perm.class_mu_1_Address[i]++;
        value(4 + Perm.undefined_class_mu_1_Address++);
      }
    else 
      {
        value(Perm.class_mu_1_Address[value()-4]+4);
      }
}
void mu_1_Address::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Address::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Address[value()-4]==Perm.undefined_class_mu_1_Address) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Address[i] == Perm.undefined_class_mu_1_Address && i!=value()-4)
            Perm.class_mu_1_Address[i]++;
        Perm.undefined_class_mu_1_Address++;
      }
}
void mu_1_Address::ArrayLimit(PermSet& Perm) {}
void mu_1_Address::Limit(PermSet& Perm) {}
void mu_1_Address::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_TSr::Permute(PermSet& Perm, int i) {};
void mu_1_TSr::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_TSr::Canonicalize(PermSet& Perm) {};
void mu_1_TSr::SimpleLimit(PermSet& Perm) {};
void mu_1_TSr::ArrayLimit(PermSet& Perm) {};
void mu_1_TSr::Limit(PermSet& Perm) {};
void mu_1_TSr::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_ids::Permute(PermSet& Perm, int i) {};
void mu_1_ids::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ids::Canonicalize(PermSet& Perm) {};
void mu_1_ids::SimpleLimit(PermSet& Perm) {};
void mu_1_ids::ArrayLimit(PermSet& Perm) {};
void mu_1_ids::Limit(PermSet& Perm) {};
void mu_1_ids::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_CacheStates::Permute(PermSet& Perm, int i) {};
void mu_1_CacheStates::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_CacheStates::Canonicalize(PermSet& Perm) {};
void mu_1_CacheStates::SimpleLimit(PermSet& Perm) {};
void mu_1_CacheStates::ArrayLimit(PermSet& Perm) {};
void mu_1_CacheStates::Limit(PermSet& Perm) {};
void mu_1_CacheStates::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
  mu_adr.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_adr.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_adr.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1_CacheLine::Permute(PermSet& Perm, int i)
{
};
void mu_1_CacheLine::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_CacheLine::Canonicalize(PermSet& Perm)
{
};
void mu_1_CacheLine::SimpleLimit(PermSet& Perm){}
void mu_1_CacheLine::ArrayLimit(PermSet& Perm){}
void mu_1_CacheLine::Limit(PermSet& Perm)
{
};
void mu_1_CacheLine::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=4; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Address[Perm.in_mu_1_Address[i]][j-4]];};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Address;
  int compare;
  static mu_1_CacheLine value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Address[2];
  bool pos_mu_1_Address[2][2];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_Address[2];
  int start_mu_1_Address[2];
  // canonicalization
  static mu_1__type_0 temp;
  // sorting mu_1_Address
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Address[i][j]=FALSE;
      count_mu_1_Address = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Address; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+4]);
              if (compare==0)
                {
                  pos_mu_1_Address[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Address; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<2; z++)
                        pos_mu_1_Address[k][z] = pos_mu_1_Address[k-1][z];
                    }
                  value[j] = (*this)[i+4];
                  for (z=0; z<2; z++)
                    pos_mu_1_Address[j][z] = FALSE;
                  pos_mu_1_Address[j][i] = TRUE;
                  count_mu_1_Address++;
                  break;
                }
            }
          if (j==count_mu_1_Address)
            {
              value[j] = (*this)[i+4];
              for (z=0; z<2; z++)
                pos_mu_1_Address[j][z] = FALSE;
              pos_mu_1_Address[j][i] = TRUE;
              count_mu_1_Address++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address() && count_mu_1_Address>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Address; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Address[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Address[i][k] && Perm.class_mu_1_Address[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Address[k] = TRUE;
                    pos_mu_1_Address[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Address[k]>j
                            || ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) )
                          Perm.class_mu_1_Address[k]++;
                      Perm.undefined_class_mu_1_Address++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_Address())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_Address; j++) // class number
        {
          class_size = 0;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Address[k]==j)
              class_size++;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Address[k]==j)
              {
                size_mu_1_Address[k] = class_size;
                start_mu_1_Address[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
         if (i >=start_mu_1_Address[j] 
             && i < start_mu_1_Address[j] + size_mu_1_Address[j])
           {
             array[i+0] = temp[j+4];
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<2; j++)
        array[Perm.class_mu_1_Address[j]+0] = temp[j+4];
    }
}
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Address;
  int compare;
  static mu_1_CacheLine value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Address[2];
  bool pos_mu_1_Address[2][2];
  // sorting mu_1_Address
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Address[i][j]=FALSE;
      count_mu_1_Address = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Address; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+4]);
              if (compare==0)
                {
                  pos_mu_1_Address[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Address; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<2; z++)
                        pos_mu_1_Address[k][z] = pos_mu_1_Address[k-1][z];
                    }
                  value[j] = (*this)[i+4];
                  for (z=0; z<2; z++)
                    pos_mu_1_Address[j][z] = FALSE;
                  pos_mu_1_Address[j][i] = TRUE;
                  count_mu_1_Address++;
                  break;
                }
            }
          if (j==count_mu_1_Address)
            {
              value[j] = (*this)[i+4];
              for (z=0; z<2; z++)
                pos_mu_1_Address[j][z] = FALSE;
              pos_mu_1_Address[j][i] = TRUE;
              count_mu_1_Address++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address() && count_mu_1_Address>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Address; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Address[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Address[i][k] && Perm.class_mu_1_Address[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Address[k] = TRUE;
                    pos_mu_1_Address[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Address[k]>j
                            || ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) )
                          Perm.class_mu_1_Address[k]++;
                      Perm.undefined_class_mu_1_Address++;
                    }
                }
            }
        }
    }
}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_CacheEntry::Permute(PermSet& Perm, int i)
{
  mu_CL.Permute(Perm,i);
};
void mu_1_CacheEntry::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_CacheEntry::Canonicalize(PermSet& Perm)
{
  mu_CL.Canonicalize(Perm);
};
void mu_1_CacheEntry::SimpleLimit(PermSet& Perm){}
void mu_1_CacheEntry::ArrayLimit(PermSet& Perm)
{
  mu_CL.ArrayLimit(Perm);
};
void mu_1_CacheEntry::Limit(PermSet& Perm)
{
};
void mu_1_CacheEntry::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=4; j<=5; j++)
     (*this)[j].value(temp[Perm.revperm_mu_1_Address[Perm.in_mu_1_Address[i]][j-4]].value());};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Address;
  int compare;
  static mu_1_CacheStates value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Address[2];
  bool pos_mu_1_Address[2][2];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_Address[2];
  int start_mu_1_Address[2];
  // canonicalization
  static mu_1__type_1 temp;
  // sorting mu_1_Address
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Address[i][j]=FALSE;
      count_mu_1_Address = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Address; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+4]);
              if (compare==0)
                {
                  pos_mu_1_Address[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Address; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_Address[k][z] = pos_mu_1_Address[k-1][z];
                    }
                  value[j].value((*this)[i+4].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_Address[j][z] = FALSE;
                  pos_mu_1_Address[j][i] = TRUE;
                  count_mu_1_Address++;
                  break;
                }
            }
          if (j==count_mu_1_Address)
            {
                value[j].value((*this)[i+4].value());
              for (z=0; z<2; z++)
                pos_mu_1_Address[j][z] = FALSE;
              pos_mu_1_Address[j][i] = TRUE;
              count_mu_1_Address++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address() && count_mu_1_Address>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Address; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Address[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Address[i][k] && Perm.class_mu_1_Address[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Address[k] = TRUE;
                    pos_mu_1_Address[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Address[k]>j
                            || ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) )
                          Perm.class_mu_1_Address[k]++;
                      Perm.undefined_class_mu_1_Address++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_Address())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_Address; j++) // class number
        {
          class_size = 0;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Address[k]==j)
              class_size++;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Address[k]==j)
              {
                size_mu_1_Address[k] = class_size;
                start_mu_1_Address[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
         if (i >=start_mu_1_Address[j] 
             && i < start_mu_1_Address[j] + size_mu_1_Address[j])
           {
             array[i+0].value(temp[j+4].value());
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<2; j++)
        array[Perm.class_mu_1_Address[j]+0].value(temp[j+4].value());
    }
}
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Address;
  int compare;
  static mu_1_CacheStates value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Address[2];
  bool pos_mu_1_Address[2][2];
  // sorting mu_1_Address
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Address[i][j]=FALSE;
      count_mu_1_Address = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Address; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+4]);
              if (compare==0)
                {
                  pos_mu_1_Address[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Address; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_Address[k][z] = pos_mu_1_Address[k-1][z];
                    }
                  value[j].value((*this)[i+4].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_Address[j][z] = FALSE;
                  pos_mu_1_Address[j][i] = TRUE;
                  count_mu_1_Address++;
                  break;
                }
            }
          if (j==count_mu_1_Address)
            {
                value[j].value((*this)[i+4].value());
              for (z=0; z<2; z++)
                pos_mu_1_Address[j][z] = FALSE;
              pos_mu_1_Address[j][i] = TRUE;
              count_mu_1_Address++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address() && count_mu_1_Address>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Address; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Address[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Address[i][k] && Perm.class_mu_1_Address[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Address[k] = TRUE;
                    pos_mu_1_Address[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Address[k]>j
                            || ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) )
                          Perm.class_mu_1_Address[k]++;
                      Perm.undefined_class_mu_1_Address++;
                    }
                }
            }
        }
    }
}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_WState::Permute(PermSet& Perm, int i)
{
  mu_CL.Permute(Perm,i);
};
void mu_1_WState::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_WState::Canonicalize(PermSet& Perm)
{
  mu_CL.Canonicalize(Perm);
};
void mu_1_WState::SimpleLimit(PermSet& Perm){}
void mu_1_WState::ArrayLimit(PermSet& Perm)
{
  mu_CL.ArrayLimit(Perm);
};
void mu_1_WState::Limit(PermSet& Perm)
{
};
void mu_1_WState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<18; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[18];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Address, oldcount_mu_1_Address;
  bool pos_mu_1_Address[2][2];
  bool goodset_mu_1_Address[2];
  int count_mu_1_Cache, oldcount_mu_1_Cache;
  bool pos_mu_1_Cache[3][3];
  bool goodset_mu_1_Cache[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[18][18];
  bool goodset_multisetindex[18];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 18; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 18; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 18; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Address[i][j]=FALSE;
  count_mu_1_Address = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Address[i] == count_mu_1_Address)
         {
           pos_mu_1_Address[count_mu_1_Address][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Address++;
      else break;
    }
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Cache[i][j]=FALSE;
  count_mu_1_Cache = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Cache[i] == count_mu_1_Cache)
         {
           pos_mu_1_Cache[count_mu_1_Cache][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Cache++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Address() && count_mu_1_Address<2);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Cache() && count_mu_1_Cache<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Address = count_mu_1_Address;
      oldcount_mu_1_Cache = count_mu_1_Cache;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Cache() && count_mu_1_Cache<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_src.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Cache; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Cache[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_src.isundefined()
                          && pos_mu_1_Cache[j][(*this)[k].mu_src-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Cache[(*this)[k].mu_src-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Cache[j][k] && !goodset_mu_1_Cache[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Cache; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Cache[z][k] = pos_mu_1_Cache[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Cache[j][k] && !goodset_mu_1_Cache[k])
                                  pos_mu_1_Cache[j][k] = FALSE;
                                if (pos_mu_1_Cache[j+1][k] && goodset_mu_1_Cache[k])
                                  pos_mu_1_Cache[j+1][k] = FALSE;
                              }
                            count_mu_1_Cache++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Address() && count_mu_1_Address<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_adr.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Address; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Address[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_adr.isundefined()
                          && pos_mu_1_Address[j][(*this)[k].mu_adr-4])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Address[(*this)[k].mu_adr-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Address[j][k] && !goodset_mu_1_Address[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Address; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Address[z][k] = pos_mu_1_Address[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Address[j][k] && !goodset_mu_1_Address[k])
                                  pos_mu_1_Address[j][k] = FALSE;
                                if (pos_mu_1_Address[j+1][k] && goodset_mu_1_Address[k])
                                  pos_mu_1_Address[j+1][k] = FALSE;
                              }
                            count_mu_1_Address++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Address!=count_mu_1_Address);
      while_guard = while_guard || (oldcount_mu_1_Cache!=count_mu_1_Cache);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Address<2;
      while_guard = while_guard || count_mu_1_Cache<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Address())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Address[i][j])
            Perm.class_mu_1_Address[j] = i;
      Perm.undefined_class_mu_1_Address=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Address[j]>Perm.undefined_class_mu_1_Address)
          Perm.undefined_class_mu_1_Address=Perm.class_mu_1_Address[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Cache[i][j])
            Perm.class_mu_1_Cache[j] = i;
      Perm.undefined_class_mu_1_Cache=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Cache[j]>Perm.undefined_class_mu_1_Cache)
          Perm.undefined_class_mu_1_Cache=Perm.class_mu_1_Cache[j];
    }
  }
}
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Cache[Perm.in_mu_1_Cache[i]][j-1]];};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Cache;
  int compare;
  static mu_1__type_2 value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Cache[3];
  bool pos_mu_1_Cache[3][3];
  // sorting mu_1_Cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Cache[i][j]=FALSE;
      count_mu_1_Cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Cache; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Cache[k][z] = pos_mu_1_Cache[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Cache[j][z] = FALSE;
                  pos_mu_1_Cache[j][i] = TRUE;
                  count_mu_1_Cache++;
                  break;
                }
            }
          if (j==count_mu_1_Cache)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Cache[j][z] = FALSE;
              pos_mu_1_Cache[j][i] = TRUE;
              count_mu_1_Cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Cache() && count_mu_1_Cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Cache[i][k] && Perm.class_mu_1_Cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Cache[k] = TRUE;
                    pos_mu_1_Cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Cache[k] == j && !goodset_mu_1_Cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Cache[k]>j
                            || ( Perm.class_mu_1_Cache[k] == j && !goodset_mu_1_Cache[k] ) )
                          Perm.class_mu_1_Cache[k]++;
                      Perm.undefined_class_mu_1_Cache++;
                    }
                }
            }
        }
    }
}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Cache[Perm.in_mu_1_Cache[i]][j-1]];};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm){};
void mu_1__type_4::SimpleLimit(PermSet& Perm){}
void mu_1__type_4::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Cache;
  int compare;
  static mu_1_CacheEntry value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Cache[3];
  bool pos_mu_1_Cache[3][3];
  // sorting mu_1_Cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Cache[i][j]=FALSE;
      count_mu_1_Cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Cache; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Cache[k][z] = pos_mu_1_Cache[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Cache[j][z] = FALSE;
                  pos_mu_1_Cache[j][i] = TRUE;
                  count_mu_1_Cache++;
                  break;
                }
            }
          if (j==count_mu_1_Cache)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Cache[j][z] = FALSE;
              pos_mu_1_Cache[j][i] = TRUE;
              count_mu_1_Cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Cache() && count_mu_1_Cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Cache[i][k] && Perm.class_mu_1_Cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Cache[k] = TRUE;
                    pos_mu_1_Cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Cache[k] == j && !goodset_mu_1_Cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Cache[k]>j
                            || ( Perm.class_mu_1_Cache[k] == j && !goodset_mu_1_Cache[k] ) )
                          Perm.class_mu_1_Cache[k]++;
                      Perm.undefined_class_mu_1_Cache++;
                    }
                }
            }
        }
    }
}
void mu_1__type_4::Limit(PermSet& Perm){}
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Cache[Perm.in_mu_1_Cache[i]][j-1]];};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Cache;
  int compare;
  static mu_1_WState value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Cache[3];
  bool pos_mu_1_Cache[3][3];
  // sorting mu_1_Cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Cache[i][j]=FALSE;
      count_mu_1_Cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Cache; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Cache[k][z] = pos_mu_1_Cache[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Cache[j][z] = FALSE;
                  pos_mu_1_Cache[j][i] = TRUE;
                  count_mu_1_Cache++;
                  break;
                }
            }
          if (j==count_mu_1_Cache)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Cache[j][z] = FALSE;
              pos_mu_1_Cache[j][i] = TRUE;
              count_mu_1_Cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Cache() && count_mu_1_Cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Cache[i][k] && Perm.class_mu_1_Cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Cache[k] = TRUE;
                    pos_mu_1_Cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Cache[k] == j && !goodset_mu_1_Cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Cache[k]>j
                            || ( Perm.class_mu_1_Cache[k] == j && !goodset_mu_1_Cache[k] ) )
                          Perm.class_mu_1_Cache[k]++;
                      Perm.undefined_class_mu_1_Cache++;
                    }
                }
            }
        }
    }
}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=4; j<=5; j++)
     (*this)[j].value(temp[Perm.revperm_mu_1_Address[Perm.in_mu_1_Address[i]][j-4]].value());};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_6::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Address;
  int compare;
  static mu_1_TSr value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Address[2];
  bool pos_mu_1_Address[2][2];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_Address[2];
  int start_mu_1_Address[2];
  // canonicalization
  static mu_1__type_6 temp;
  // sorting mu_1_Address
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Address[i][j]=FALSE;
      count_mu_1_Address = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Address; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+4]);
              if (compare==0)
                {
                  pos_mu_1_Address[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Address; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_Address[k][z] = pos_mu_1_Address[k-1][z];
                    }
                  value[j].value((*this)[i+4].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_Address[j][z] = FALSE;
                  pos_mu_1_Address[j][i] = TRUE;
                  count_mu_1_Address++;
                  break;
                }
            }
          if (j==count_mu_1_Address)
            {
                value[j].value((*this)[i+4].value());
              for (z=0; z<2; z++)
                pos_mu_1_Address[j][z] = FALSE;
              pos_mu_1_Address[j][i] = TRUE;
              count_mu_1_Address++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address() && count_mu_1_Address>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Address; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Address[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Address[i][k] && Perm.class_mu_1_Address[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Address[k] = TRUE;
                    pos_mu_1_Address[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Address[k]>j
                            || ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) )
                          Perm.class_mu_1_Address[k]++;
                      Perm.undefined_class_mu_1_Address++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_Address())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_Address; j++) // class number
        {
          class_size = 0;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Address[k]==j)
              class_size++;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Address[k]==j)
              {
                size_mu_1_Address[k] = class_size;
                start_mu_1_Address[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
         if (i >=start_mu_1_Address[j] 
             && i < start_mu_1_Address[j] + size_mu_1_Address[j])
           {
             array[i+0].value(temp[j+4].value());
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<2; j++)
        array[Perm.class_mu_1_Address[j]+0].value(temp[j+4].value());
    }
}
void mu_1__type_6::SimpleLimit(PermSet& Perm){}
void mu_1__type_6::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Address;
  int compare;
  static mu_1_TSr value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Address[2];
  bool pos_mu_1_Address[2][2];
  // sorting mu_1_Address
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Address[i][j]=FALSE;
      count_mu_1_Address = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Address; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+4]);
              if (compare==0)
                {
                  pos_mu_1_Address[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Address; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_Address[k][z] = pos_mu_1_Address[k-1][z];
                    }
                  value[j].value((*this)[i+4].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_Address[j][z] = FALSE;
                  pos_mu_1_Address[j][i] = TRUE;
                  count_mu_1_Address++;
                  break;
                }
            }
          if (j==count_mu_1_Address)
            {
                value[j].value((*this)[i+4].value());
              for (z=0; z<2; z++)
                pos_mu_1_Address[j][z] = FALSE;
              pos_mu_1_Address[j][i] = TRUE;
              count_mu_1_Address++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Address() && count_mu_1_Address>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Address; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Address[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Address[i][k] && Perm.class_mu_1_Address[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Address[k] = TRUE;
                    pos_mu_1_Address[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Address[k]>j
                            || ( Perm.class_mu_1_Address[k] == j && !goodset_mu_1_Address[k] ) )
                          Perm.class_mu_1_Address[k]++;
                      Perm.undefined_class_mu_1_Address++;
                    }
                }
            }
        }
    }
}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_c_TS.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_c_TS.MultisetSort();
              mu_net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_net.MultisetSort();
              mu_caches.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_caches.MultisetSort();
              mu_wstates.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_wstates.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_c_TS.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_c_TS.MultisetSort();
          mu_net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_net.MultisetSort();
          mu_caches.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_caches.MultisetSort();
          mu_wstates.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_wstates.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_c_TS.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_c_TS.MultisetSort();
              mu_net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_net.MultisetSort();
              mu_caches.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_caches.MultisetSort();
              mu_wstates.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_wstates.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_c_TS.MultisetSort();
      mu_net.MultisetSort();
      mu_caches.MultisetSort();
      mu_wstates.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_c_TS.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_c_TS.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_caches.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_caches.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_wstates.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_wstates.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_c_TS.Canonicalize(Perm);

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_caches.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_caches.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_wstates.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_wstates.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_c_TS.Canonicalize(Perm);

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_net.MultisetSort();
  mu_caches.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_caches.MultisetSort();
  mu_wstates.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_wstates.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_net.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_net.MultisetSort();
      mu_caches.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_caches.MultisetSort();
      mu_wstates.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_wstates.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_c_TS.Canonicalize(Perm);

  Perm.SimpleToOne();

  mu_net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_net.MultisetSort();

  mu_caches.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_caches.MultisetSort();

  mu_wstates.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_wstates.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"
