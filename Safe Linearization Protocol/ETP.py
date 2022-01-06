 # PPP - Python (Cache) Protocol Parser
 # NOS - Nicolai Oswald
 # VER - 0
 # Name conventions according to Chris Banks and Marco Elvier
 # In {name}.m file:
 # "MessageType"	- Message type declarations
 # "L1CacheState"	- Cache States
 # "DirectoryState"	- Directory States
 #
 # Graph edge labels: TRIG/IN/OUT
 #	TRIG	- Load/Store
 # 	IN 		- Incoming message
 #  OUT		- Outgoing message

# Imports
import os, re, string
from seqdiag import parser, builder, drawer

class CCState:
    Keys = ["state","id","TS","lid","inv_ack", "upd_ack"];

    def __init__(self, name, indicator):
    	self.Name = name
    	self.Indicator = indicator
    	self.State = ""
    	self.Cid = ""
    	self.TS = ""
    	self.Rid = ""
    	self.Inv_ack = ""
	self.Upd_ack = ""

    def update(self, State, Cid, TS, Rid, Inv_ack, Upd_ack):
    	if (State!=""):
    		self.State=State

    	if (Cid!=""):
    		self.Cid=Cid

    	if (TS!=""):
    		self.TS=TS    		

    	if (Rid!=""):
    		self.Rid=Rid

    	if (Inv_ack!=""):
    		self.Inv_ack=Inv_ack

	if (Upd_ack!=""):
    		self.Upd_ack=Upd_ack

    def update_Str(self, Key, val):
    	if (Key=="state") and len(Key)==len("state"):
    		self.State=val

    	if (Key=="id") and len(Key)==len("id"):
    		self.Cid=val

    	if (Key=="TS") and len(Key)==len("TS"):
    		self.TS=val    		

    	if (Key=="lid") and len(Key)==len("lid"):
    		self.Rid=val

    	if (Key=="inv_ack") and len(Key)==len("inv_ack"):
    		self.Inv_ack=val

    	if (Key=="upd_ack") and len(Key)==len("upd_ack"):
    		self.Upd_ack=val

class MSG:
    Keys = ["mtype","src","TS","id"];
    MREQ = ["Get", "Inv"];
    MFWD = ["Fwd"]
    MRES = ["Ack"]

    def __init__(self):
    	self.mtype= ""
    	self.src = ""
    	self.dst = ""
    	self.TS = ""
    	self.mid = ""
    	self.color = "red"

    def setcolor(self,mtype):
    	for key in self.MREQ:
    		if re.search(key,mtype):
    			self.color = "red"

		for key in self.MFWD:
			if re.search(key,mtype):
				self.color = "yellow"

		for key in self.MRES:
			if re.search(key,mtype):
				self.color = "blue"

    def update(self, mtype, src, dst, TS, mid):
    	if (mtype!=""):
    		self.mtype=mtype
    		self.setcolor(mtype)

    	if (src!=""):
    		self.src=src

    	if (dst!=""):
    		self.dst=dst    		

    	if (TS!=""):
    		self.TS=TS

    	if (mid!=""):
    		self.mid=mid

    def update_Str(self, Key, val):
    	if (Key=="mtype") and len(Key)==len("mtype"):
    		self.mtype=val
    		self.setcolor(val)

    	if (Key=="src") and len(Key)==len("src"):
    		self.src=val

    	if (Key=="dst") and len(Key)==len("dst"):
    		self.dst=val    		

    	if (Key=="TS") and len(Key)==len("TS"):
    		self.TS=val

    	if (Key=="id") and len(Key)==len("id"):
    		self.mid=val

    def update_dst(self, val):
    	self.dst=val

    def print_MSG(self):
    	print self.mtype
    	print self.src
    	print self.dst
    	print self.TS
    	print self.mid

def Keyword_Search (file,keyword,dbg):
	lNr=[]
	# Find keywords in text and return line array
	for ind in range (0, len(file)):
		# Detect comments in line to avoid accidental use of Kewords
		if "--" in file[ind]:
			lfile=file[ind].split("--", 1)[0]
		else:
			lfile=file[ind]

		if keyword in lfile:
			lNr.append(ind)
			if dbg:
				print keyword,' found at line:', ind, ' ==> ', lfile
	return lNr

def Keyword_Search_Region (file,keyword,start,end,dbg):
	lNr=[]
	# Check if a certain keywords occur within a certain range of line
	for ind in range(start,end):
		if re.search(keyword,file[ind]):
			lNr.append(ind)
			if dbg:
				print 'Search range "', keyword, '" found at line:', ind, ' ==> ', file[ind]
	return lNr

def Keyword_Search_Region_Brackets (file,keyword,start,end,dbg):
	lNr=[]
	prebracket=keyword.split("[", 1)[0]
	bracket=(keyword.split("[", 1)[1]).split("]", 1)[0]
	# Check if a certain keywords occur within a certain range of line
	for ind in range(start,end):
		if re.search(prebracket,file[ind]) and re.search(bracket,file[ind]) :
			lNr.append(ind)
			if dbg:
				print 'Search range "', keyword, '" found at line:', ind, ' ==> ', file[ind]
	return lNr

def Extract_Value_Line(file,keyword,line,dbg):
	if re.search("[^\w]"+keyword+"[^\w]",file[line]):
		Entry=file[line].split(":", 1)[1];
		return Entry
	return ""	

def Extract_Value_Region(file,keyword,start,end,dbg):
	for ind in range(start,end):
		if re.search(keyword,file[ind]):
			Entry=file[ind].split(":", 1)[1];
			return Entry
	return ""

def GetNodes (file,keyword,start,end,dbg):
	NodeLines=Keyword_Search_Region(file,keyword,start,end,dbg)
	Nodes=[]
	for ind in NodeLines:
		Indicator=file[ind].split(".", 1)[0];
		if re.search(r"]",Indicator):
			# Array of Nodes
			Entry=Indicator.split("[", 1)[1]
			Entry=Entry.split("]", 1)[0]
		Nodes.append(CCState(Entry,Indicator));
	return Nodes

def GetNode(file,ind,dbg):
	Entry=file[ind].split(".", 1)[0];
	if re.search(r"]",Entry):
		Entry=Entry.split("[", 1)[1]
		Entry=Entry.split("]", 1)[0]
	return Entry

def GetTransition (file,nodes,mkey,ckey,start,end,dbg):
	aMSG=[]
	SRC=""
	nSRC=0
	chgNodes=[]
	seq=""
	State=""

	# Get the operation Header
	seq+=OperationHeader(file[start])

	# Get the source
	for ind in range(0,len(nodes)):
		Node=nodes[ind]
		if re.search(Node.Name,file[start]):
			SRC=Node.Name
			nInd=ind

		# USE INDICATORS TO DETECT ALL CACHE RELATED THINGS
	for ind in range(0,len(nodes)):
		Node=nodes[ind]
		iCC=Keyword_Search_Region_Brackets(file,Node.Indicator,start,end,dbg)
		if len(iCC)>0:
			# Analyze all entries
			for ind in iCC:
				for key in Node.Keys:
					data=Extract_Value_Line(file,key,ind,dbg)
					if data!="":
						Node.update_Str(key,data)
			chgNodes.append(Node)

	# Get all messages
	iMSG=Keyword_Search_Region(file,mkey,start,end,dbg)
	iMSG.append(end);

	# Iterate over all messages and read out the information
	for ind in range(0, len(iMSG)-1):
		lMSG=MSG();
		Entry=file[iMSG[ind]]
		lDST=Entry.split("[", 1)[1]
		lDST=lDST.split("]", 1)[0]
		lMSG.update_dst(lDST)

		for key in lMSG.Keys:
			lMSG.update_Str(key,Extract_Value_Region(file,key,iMSG[ind],iMSG[ind+1],dbg))
		# Check if final state: (More than one Node active => All Caches are reported)
		if len(chgNodes)<2:
			if lMSG.src==SRC: 
				aMSG.append(lMSG)
		else:
			aMSG.append(lMSG)



	if SRC!="":
		# Draw all Messages
		Node=nodes[nInd]
		if len(chgNodes)<2:
			State=Node.State+"\n"+"Cid: "+Node.Cid+"\n"+"TS: "+Node.TS+"\n"+"Rid: "+Node.Rid+"\n"+"Inv_ack: "+Node.Inv_ack +"\n"+"Upd_ack: "+Node.Upd_ack
		else:
			State=""
		seq+=DrawMessages(nodes,aMSG,State,1)

	if len(chgNodes)>2 or (len(aMSG)==0 and len(chgNodes)>0):
		seq+=DrawNodes(chgNodes)

	return seq


def SeqConfig():
	seq=("seqdiag {")
	seq+=("\n")
	seq+=("activation = none;")
	seq+=("\n")
	seq+=("\n")
	return seq

def SeqEnd():
	seq=("}")
	seq+=("\n")
	return seq

def InitState():
	seq=("=== Start State End ===")
	seq+=("\n")
	return seq

def FinalState():
	seq=("=== Final State Begin ===")
	seq+=("\n")
	return seq

def OperationHeader(Header):
	seq=("=== "+Header+" ===")
	seq+=("\n")
	return seq

def Connection(Source, Destination, Name, Color, lState, rState):
	seq=(Source + " -> " + Destination)
	seq+=("[")
	comma=0; 

	if (Name!=""):
		seq+=(" label=\"" + Name +"\" ")
		comma=1

	if (Color!=""):
		if comma==1:
			seq+=','
		else:
			comma=1
		seq+=(" color=\"" + Color +"\" ")

	if (lState!=""):
		if comma==1:
			seq+=','
		else:
			comma=1
		seq+=(" leftnote=\"" + lState +"\" ")

	if (rState!=""):
		if comma==1:
			seq+=','
		else:
			comma=1
		seq+=(" rightnote=\"" + rState +"\" ")

	seq+=("];")
	seq+=("\n")
	return seq

def DrawNodes(nodes):
	seq=""
	for Node in nodes:
		State=Node.State+"\n"+"Cid: "+Node.Cid+"\n"+"TS: "+Node.TS+"\n"+"Rid: "+Node.Rid+"\n"+"Inv_ack: "+Node.Inv_ack +"\n"+"Upd_ack: "+Node.Upd_ack
		seq+=Connection(Node.Name, Node.Name, "", "", State,"")
	return seq

def DrawMessages(Nodes,aMSG,State,once):
	seq=""
	for ind in range(0,len(aMSG)):
		lMSG=aMSG[ind]
		if lMSG.mtype!="Undefined":
			MSGPayload=lMSG.mtype+" / "+"TS="+lMSG.TS+" / "+"mid="+lMSG.mid
			# Connection(Source, Destination, Name, Color, State)
			if once==1 and ind>0:
				seq+=Connection(lMSG.src, lMSG.dst, MSGPayload, lMSG.color,"","")
			else:
				# For every node determine if State shall be written either left or right
				# All nodes are drawn in the order they are maintained in the list node
				for Node in nodes:
					if re.search(lMSG.src,Node.Name):
						seq+=Connection(lMSG.src, lMSG.dst, MSGPayload, lMSG.color, State,"")
						break
					if re.search(lMSG.dst,Node.Name):
						seq+=Connection(lMSG.src, lMSG.dst, MSGPayload, lMSG.color, "",State)
						break
	return seq


def SaveSequenceDiag(seq,filename,dtype):
	tree = parser.parse_string(seq)
	diagram = builder.ScreenNodeBuilder.build(tree)
	draw = drawer.DiagramDraw(dtype, diagram, filename=filename+"."+dtype)
	draw.draw()
	draw.save()




### Main Program startGet_Nested_Keys
filename='VIW.txt'
outfilename=filename+".diag"
outformat="png"					#"svg" is alternative option

dbg=0;

print ("Error Trace (Cache Coherence Protocol) Parser")

seq=""

# Key words for which it must be searched in text
# Cache Controller
StartState="Startstate"
Rule="Rule"
End="Result:"
ckey="\.state"
mkey="mtype"


file = open(filename).read().splitlines()

Rules=Keyword_Search(file,StartState,dbg)
Rules+=Keyword_Search(file,Rule,dbg)
Rules+=Keyword_Search(file,End,dbg)

# For every Rule section search for keywords and create transactions
# First determine the number of caches
nodes = GetNodes(file,ckey,Rules[0],Rules[1],dbg)

# Initialize transition
seq+=SeqConfig()

for ind in range(0, len(Rules)-1):
	retseq=GetTransition(file,nodes,mkey,ckey,Rules[ind],Rules[ind+1],dbg)

	if retseq!="":
		seq+=retseq

seq+=SeqEnd()

print "\n\n Sequential Diagram Description:"
print seq

print ("Trace Complete")



# Save file output
path = "ETP_"+filename.split(".", 1)[0]

if not (os.path.isdir(path)):
	os.mkdir(path) 

os.chdir(path)

fout = open(outfilename, 'w')
fout.write(seq)

SaveSequenceDiag(seq,filename,outformat)
