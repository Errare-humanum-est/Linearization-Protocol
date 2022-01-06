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
import pygraphviz as pgv
from graphviz import Digraph

# Functions
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

def Keyword_Search_Next (file,keyword,line,dbg):
	lNr=[]
	# Check if a certain keywords occur within a certain range of line
	for ind in range (line, len(file)):
		# Detect comments in line to avoid accidental use of Kewords
		if "--" in file[ind]:
			lfile=file[ind].split("--", 1)[0]
		else:
			lfile=file[ind]
		if keyword in lfile:
			if dbg:
				print 'Search next "', keyword, '" found at line:', ind, ' ==> ', lfile
			return ind
	return 0

def Keyword_Search_Region (file,keyword,lines,rsize,dbg):
	lNr=[]
	# Check if a certain keywords occur within a certain range of line
	for ind in range (0, len(lines)):
		for num in range(lines[ind], min(lines[ind]+rsize, len(file))):
			# Detect comments in line to avoid accidental use of Kewords
			if "--" in file[num]:
				lfile=file[num].split("--", 1)[0]
			else:
				lfile=file[num]
			if keyword in lfile:
				lNr.append(num)
				if dbg:
					print 'Search range "', keyword, '" found at line:', num, ' ==> ', lfile
	return lNr

def Keywords_Def_Extract (file,line,dbg):
	lNr=[]
	# Search for start and end of bracket section
	for ind in range (line, len(file)):
		if "{" in file[ind]:
			lNr.insert(0,ind)
		if "}" in file[ind]:
			lNr.insert(1,ind)
			break

	# Remove brackets
	file[lNr[0]]=file[lNr[0]].split("{", 1)[1]
	file[lNr[1]]=file[lNr[1]].split("}", 1)[0]

	# Remove comments
	for ind in range (lNr[0],lNr[1]+1):
		file[ind]=file[ind].split("--", 1)[0]

	# Concatenate remaining elements and remove all but accepted characters
	concStr = ''.join(file[lNr[0]:lNr[1]])
	elements = re.sub('[^a-zA-Z0-9_\-\>\<,]', '', concStr)
	if dbg: print elements

	# Create list of extracted elements
	elements = elements.split(',')

	if dbg:
		print "Extracted elements:"
		for ind in range(0, len(elements)):
			print elements[ind]

	# Return list of elements
	return elements

def Keywords_Multiple_Check(file,start,end,Keywords,Single):
	# Find "case State" in FSM function
	for ind in range (start,end):

		# Detect comments in line to avoid accidental use of Kewords
		if "--" in file[ind]:
			lfile=file[ind].split("--", 1)[0]
		else:
			lfile=file[ind]


		if re.search(r"[\s\(]"+Single+r"(?!\w)",lfile):
			# Now search for keyword
			for indK in range (0,len(Keywords)):
				if re.search("\s"+Keywords[indK],lfile):
					return ind
	return 0

def Keywords_Multiple_List(file,start,end,Keys,FuncKeys):

	# Sort Keywords according to length, to avoid wrong state detection because
	# in a long state word a substring match is detected
	lFuncKeys=FuncKeys
	lFuncKeys.sort(key=len, reverse=True)

	# Create array to store lines of case statements
	StateLines = [[0 for x in range(2)] for y in range(len(lFuncKeys))]
	for indS in range (0, len(lFuncKeys)):
		# Find all the keywords and their corresponding lines
		StateLines[indS]=[Keywords_Multiple_Check(file, start, end, Keys,
													lFuncKeys[indS]), lFuncKeys[indS]]
		# No Assertion if state is not found!
		# Then line entry remains 0, state not defined yet

	return StateLines

def Matrix_Remove_Empty(Matrix):
	# Remove all zero elements from matrix
	nZMatrix=[]
	for ind in range (0,len(Matrix)):
		if(Matrix[ind][0])!=0:
			nZMatrix.append(Matrix[ind][:])
	return nZMatrix

def Get_Nested_If(file,start,end):
	NestingTable=[]
	NestingInd=0
	IfCount=0
	ifN=0
	Region=[]
	Regions=[]

	for ind in range(start,end):

		# Detect comments in line to avoid accidental use of Kewords
		if "--" in file[ind]:
			lfile=file[ind].split("--", 1)[0]
		else:
			lfile=file[ind]

		if re.search(r"\s"+"if"+r"(?!\w)",lfile):
			ifN=ifN+1
			IfCount=IfCount+1
			NestingInd=NestingInd+1
			NestingTable.append([ifN, 0, ind, "if"])

		if re.search(r"\s"+"else"+r"(?!\w)",lfile):
			if ifN>0:
				NestingInd=NestingInd+1
				NestingTable.append([ifN, 1, ind, "else"])

		if re.search(r"\s"+"endif"+r"(?!\w)",lfile):
			if ifN>0:
				NestingInd=NestingInd+1
				NestingTable.append([ifN, 2, ind, "endif"])
				ifN=ifN-1
		else:
			if re.search(r"\s"+"end"+r"(?!\w)",lfile):
				if ifN>0:
					NestingInd=NestingInd+1
					NestingTable.append([ifN,2, ind, "end"])
					ifN=ifN-1

	if (IfCount!=0):

		for indN in range(1,IfCount+1):
			ELSE=0;
			ifStart=0

			# Find all the IF
			for indI in range(0,len(NestingTable)):
				Entry=NestingTable[indI]
				if Entry[0]==indN:
					# Found If Start Sequence
					if Entry[1]==0:
						lstart=Entry[2]
						ifStart=Entry[2]
						ELSE=0;
					# Else was found
					if Entry[1]==1:
						Region.append([indN,lstart,Entry[2],"if..else",1,ifStart])
						lstart=Entry[2]
						ELSE=1;
					# Endif or End was found
					if Entry[1]==2:
						if ELSE==0:
							Region.append([indN,lstart,Entry[2],"if..endif",0,ifStart])
						if ELSE==1:
							Region.append([indN,lstart,Entry[2],"else..endif",2,ifStart])

		for indR in range(0,len(Region)):

			# Extract if condition
			Entry=Region[indR];
			if "--" in file[Entry[5]]:
				lfile=file[Entry[5]].split("--", 1)[0]
			else:
				lfile=file[Entry[5]]
			# Remove if condition
			lfile=re.sub("\sif\s", "", lfile)
			# Remove then
			lfile=re.sub("\sthen(?!\w)", "", lfile)
			lfile=re.sub(r"\s+", " ", lfile)
			#lfile=re.sub('[^ \w\-\>\<,\=\&\(\)\.]', '', lfile)

			if Entry[0]==1:

				#[start,end,Upper Boundary,Lower Boundary,lfile]

				if Entry[4]==0:
					# The complete code including if..endif
					Regions.append([start,end,[0],[0],lfile])
					# The complete code excluding if..endif
					Regions.append([start,end,[Entry[1]],[Entry[2]]," !{"+lfile+"}"])
				if Entry[4]==1:
					# All the code excluding the if..else condition
					Regions.append([start,end,[Entry[1]],[Entry[2]]," !{"+lfile+"}"])
				if Entry[4]==2:
					# All the code excluding the else..endif condition
					Regions.append([start,end,[Entry[1]],[Entry[2]],lfile])

			else:

				index=0
				exit=0

				while len(Regions)>0:

					exit=0
					HEntry=Regions[index]
					CondString=HEntry[4]
					UBound=list(HEntry[2])
					LBound=list(HEntry[3])

					# Iterate over all the excluded elements
					for indE in range(0,len(HEntry[2])):
						# Check if forbidden region is extended
						if ((Entry[2]<UBound[indE]) or (Entry[1]>LBound[indE])):

							if Entry[4]==0:		# if..endif
								# The complete code including if
								Regions[index][4]=CondString+" and "+lfile

								# The complete code excluding if
								UBound.append(Entry[1])
								LBound.append(Entry[2])
								Str=CondString+" and "+"!{"+lfile+"}"
								index=index+1
								Regions.insert(index,[HEntry[0],HEntry[1],UBound,LBound,Str])
								exit=1
								break
							# Assumption that if..else structure is always observed prior to
							# corresponding
							if Entry[4]==1:		# if..else
								# Leave first line including the
								# The complete code excluding if
								UBound.append(Entry[1])
								LBound.append(Entry[2])
								Str=CondString+" and "+"!{"+lfile+"}"
								index=index+1
								Regions.insert(index,[HEntry[0],HEntry[1],UBound,LBound,Str])
								exit=1
								break

							if Entry[4]==2:		# else..endif
								UBound.append(Entry[1])
								LBound.append(Entry[2])
								Str=CondString+" and "+lfile
								Regions[index]=[HEntry[0],HEntry[1],UBound,LBound,Str]
								exit=1
								break

					index=index+1
					if index>=(len(Regions)):
						break

					if exit==1:
						break


	else:
		# Without if
		Regions.append([start,end,[0],[0],"-"])

	return Regions

def Get_Nested_Keys(file,start,StartKey,EndKey):
	NestingTable=[]
	Count=0
	N=0
	ind=start-1


	for indK in range(0, len(StartKey)):
		while ind<len(file):

			# Detect comments in line to avoid accidental use of Kewords
			if "--" in file[ind]:
				lfile=file[ind].split("--", 1)[0]
			else:
				lfile=file[ind]

			if re.search(EndKey[indK],lfile):
				if N>0:
					NestingTable.append([N, 2, ind, EndKey[indK]])
					N=N-1
			elif re.search(StartKey[indK]+r"(?!\w)",lfile):
				N=N+1
				Count=Count+1
				NestingTable.append([N, 0, ind, StartKey[indK]])

			ind=ind+1

			if (Count>0 and N==0):
				break

	return NestingTable


# Extract definitions
def Get_Msg_State_Type(file,Type,EnumKey,SubSR,dbg):
	lines=Keyword_Search(file,Type,dbg)
	line=Keyword_Search_Region (file,EnumKey,lines,SubSR,dbg)
	assert not(len(line)==0), "No %s declaration found" % Type
	assert not(len(line)>1), "Multiple %s declarations found" % Type
	return (Keywords_Def_Extract (file,line[0],dbg))

# Search for directory function
def Get_FSM_Function_Start(file,Keyword,FuncKeys,SubSR,dbg):
	lines=Keyword_Search(file,Keyword,dbg)
	for ind in range (0,len(FuncKeys)):
		start=Keyword_Search_Region (file,FuncKeys[ind],lines,SubSR,dbg)
		if len(start): break	# Break criteria to speed up computation
	assert not(len(start)==0), "No %s function declaration found" % Keyword
	#assert not(len(start)>1), "Multiple %s function declaration found" % Keyword
	start=start[0];
	return start

# Search for directory function end
def Get_FSM_Function_End(file,FuncEndKey,start,dbg):
	end=Keyword_Search_Next (file,FuncEndKey[0],start,dbg)
	assert not(end==0), "No %s keyword found" % FuncEndKey[0]
	return end

# Complete incoming message transitions
def Get_In_Msg_Transitions(file,CodeRegions,Messages,States,TransKey):
	RespMsg="-"
	FinalState="-"

	StartSeq=[]
	EndSeq=[]

	StartSeq=list(CodeRegions[3])
	EndSeq=list(CodeRegions[2])

	StartSeq.append(CodeRegions[0])
	EndSeq.append(CodeRegions[1])

	StartSeq.sort()
	EndSeq.sort()

	# Remove zero entries
	if StartSeq[0]==0:
		del StartSeq[0]
	if EndSeq[0]==0:
		del EndSeq[0]

	assert (len(StartSeq)==len(EndSeq)), "Start and end sequence blocks are of different length"

	# Sort Keywords according to length, to avoid wrong state detection because
	# in a long state word a substring match is detected
	lMessages=Messages
	lMessages.sort(key=len, reverse=True)
	lStates=States
	lStates.sort(key=len, reverse=True)
	lTransKey=TransKey
	lTransKey.sort(key=len, reverse=True)

	# Scan over the complete region of validity
	for indR in range(0, len(StartSeq)):
		for ind in range(StartSeq[indR],EndSeq[indR]):

			# Detect comments in line to avoid accidental use of Kewords
			if "--" in file[ind]:
				lfile=file[ind].split("--", 1)[0]
			else:
				lfile=file[ind]

			# Search for Keywords defined in TransKey
			if any(Key in lfile for Key in lTransKey):
				for indM in range(0,len(lMessages)):
					if re.search(r"[\s\(]"+lMessages[indM]+r"(?!\w)",lfile):
						RespMsg=lMessages[indM]
						break
				for indS in range(0,len(lStates)):
					if re.search(r"\s"+lStates[indS]+r"(?!\w)",lfile):
						FinalState=lStates[indS]
						break
	return [RespMsg,FinalState]

# Detect Transitions
def Get_FSM_Transitions(file,start,end,Messages,States,DecsKey,TransKey):
	# Find lines at which the states are defined and save them into a 2D Array

	StateTrans=[]
	IfTable=[]

	# Get the lines of the defined states
	lStates=[State+"\s*"+":" for State in States]
	StateLines=Keywords_Multiple_List(file,start,end,DecsKey,States)
	# Add last line to array
	StateLines.append([end,"END"])
	StateLines=Matrix_Remove_Empty(StateLines)
	# Sort state lines incrementally
	StateLines=sorted(StateLines,key=lambda x: (x[0]))

	if dbg:
		print "State Lines \n"
		fout.write("State Lines \n" )
		for indD in range (0, len(StateLines)):
			fout.write(str(StateLines[indD])+ "\n")
			print StateLines[indD], "\n"

	# Get the lines of the defines input messages for each state
	for indS in range (0, len(StateLines)-1):
		MessageLines=Keywords_Multiple_List(file,StateLines[indS][0],
											StateLines[indS+1][0],DecsKey,Messages)
		MessageLines=Matrix_Remove_Empty(MessageLines)

		IfTable=[]

		# Sort state lines incrementally
		MessageLines=sorted(MessageLines,key=lambda x: (x[0]))

		# Search for subsegments
		for indM in range (0,len(MessageLines)):
			if indM==len(MessageLines)-1:
				# End of current case section is start of next case section
				IfTable.append([MessageLines[indM][0],MessageLines[indM][1],
					Get_Nested_If(file,MessageLines[indM][0],StateLines[indS+1][0])])
			else:
				IfTable.append([MessageLines[indM][0],MessageLines[indM][1],
					Get_Nested_If(file,MessageLines[indM][0],MessageLines[indM+1][0])])

		if dbg: print "Returned IfTable", IfTable

		# Populate State Transition Table
		for indM in range (0,len(MessageLines)):
			Lines=IfTable[indM][2]
			for indL in range (0,len(Lines)):

				StateTrans.append(
					[MessageLines[indM][0],	# Line of transition
					StateLines[indS][1],	# Initial state
					"-",					# Processor action
					MessageLines[indM][1],	# Incoming message
					"-",					# Outgoing message
					Lines[indL][4],			# Internal condition
					"-",					# Final state
					Lines[indL]])			# Code region

	# So far the initial states and the incoming messages for each transaction are known
	for ind in range (0,len(StateTrans)):
		if ind<len(StateTrans):
			data = Get_In_Msg_Transitions(	file,
											StateTrans[ind][7],
											Messages,
											States,
											TransKey)
		# data =[RespMsg,FinalState]
		StateTrans[ind][4]=data[0]
		# If final state is empty the transition loops to the initial state
		if data[1]=="-":
			StateTrans[ind][6]=StateTrans[ind][1]
		else:
			StateTrans[ind][6]=data[1]
		print data

	if dbg:
		print "\n \n Total number of state transitions: ", len(StateTrans)
		print "State Transition Table \n"
		fout.write("\n \nTotal number of state transitions: "+ str(len(StateTrans))+"\n")
		fout.write("State Transition Table \n")
		for indD in range (0, len(StateTrans)):
			print StateTrans[indD], "\n"
			fout.write(str(StateTrans[indD])+ "\n")

	return StateTrans

def Get_CPU_FSM_Transitions(file,start,end,RuleKey,RuleEndKey,Messages,States,TransKey):
	RuleStart=[]
	RuleEnd=[]
	CPUTrans=[]
	PState=0 	# Toggle parameter, as first p.state is init state and second is final state

	for ind in range(start,end):
		# Detect comments in line to avoid accidental use of Kewords
		if "--" in file[ind]:
			lfile=file[ind].split("--", 1)[0]
		else:
			lfile=file[ind]

		# Get end rule
		for indR in range (0, len(RuleEndKey)):
			if re.search(RuleEndKey[indR]+r"\s*\;",lfile):
				RuleEnd.append(ind)


		# Get start rule and Name
		for indR in range (0, len(RuleKey)):
			if re.search(RuleKey[indR]+r"(?!\w)\s",lfile):
				lfile=lfile.split("\"", 1)[1]
				lfile=lfile.split("\"", 1)[0]
				RuleStart.append([ind,lfile])

	# Check if as many rule starts as rule ends were observed
	assert (len(RuleStart)==len(RuleEnd)), "Not all rule blocks are terminated"

	# Sort Keywords according to length, to avoid wrong state detection because
	# in a long state word a substring match is detected
	lMessages=Messages
	lMessages.sort(key=len, reverse=True)
	lStates=States
	lStates.sort(key=len, reverse=True)
	lTransKey=TransKey
	lTransKey.sort(key=len, reverse=True)

	# Parse all the rules (Rule by Rule)
	for indR in range (0,len(RuleStart)):

		# Set variables by default as empty
		RespMsg="-"
		InitState="-"
		EndState="-"

		for ind in range(RuleStart[indR][0],RuleEnd[indR]):

			if "--" in file[ind]:
				lfile=file[ind].split("--", 1)[0]
			else:
				lfile=file[ind]


			# Search for Keywords defined in TransKey
			if any(Key in lfile for Key in lTransKey):

				for indM in range(0,len(lMessages)):
					if re.search(r"[\s\(]"+lMessages[indM]+r"(?!\w)",lfile):
						RespMsg=lMessages[indM]
						break

				for indS in range(0,len(lStates)):
					if re.search(r"\=\s*"+lStates[indS]+r"(?!\w)",lfile):
						if PState==0:
							InitState=lStates[indS];
							PState=1
							break
						else:
							EndState=lStates[indS];
							PState=0
							break


		CPUTrans.append(
					[RuleStart[indR][0],	# Line of transition
					InitState,				# Initial state
					RuleStart[indR][1],		# Processor action
					"-",					# Incoming message
					RespMsg,				# Outgoing message
					"-",					# Internal condition
					EndState,				# Final state
					[RuleStart[indR][0],RuleEnd[indR],[0],[0],"-"]])	# Code region

	if dbg:
		print "\n \n Total number of cpu actions: ", len(CPUTrans)
		print "CPU Transition Table \n"
		fout.write("\n \nTotal number of cpu actions: "+ str(len(CPUTrans))+"\n")
		fout.write("CPU Transition Table \n")
		for indD in range (0, len(CPUTrans)):
			print CPUTrans[indD], "\n"
			fout.write(str(CPUTrans[indD])+ "\n")

	return CPUTrans

def Graph_State_Sort(States,StateTrans,Out,In,Reverse):
	Sort=[]
	TStates=[]

	# Sorting based on number of inputs seems to create the cleanest graphs

	for indS in range (0,len(States)):
		Count=0
		for indT in range (0,len(StateTrans)):
			if Out==1:
				if re.search(States[indS]+r"(?!\w)",StateTrans[indT][1]):
					Count=Count+1
			if In==1:
				if re.search(States[indS]+r"(?!\w)",StateTrans[indT][6]):
					Count=Count+1
		Sort.append([Count, States[indS]])

	Sort.sort(reverse=Reverse)

	for ind in range (0, len(Sort)):
		TStates.append(Sort[ind][1])

	return TStates


def Create_FSM_Graph(Type,Option):

	# Compass points currently not used, as not more than 4 loops were observed
	CompassPoints=["n","ne","e","se","s","sw","w","nw","c","_"]

	# Create FSM graphs
	dStates = Digraph(Type,filename=(Type+'.gv'), engine='dot')
	# Use Splines and resolve Node overlapping
	dStates.attr(splines='true')
	# Graph direction
	dStates.attr(rankdir='LR')	#'LR'
	# Internode and edge spacing

	if Option==0:
		dStates.attr(nodesep='0.4',ranksep='2')
		dStates.attr(ratio='0.5')
	else:
		dStates.attr(nodesep='0.1',ranksep='0.3')
		dStates.attr(ratio='0.2')

	# Label[RespMsg,FinalState]
	dStates.attr(label=Type, fontsize=TextFontSize)

	return dStates


def Populate_FSM_Graph(Graph,States,StateTrans,color):

	if isinstance(color, (str, unicode)):
		lcolor=color
	else:
		lcolor='black'

	dStates=Graph

	if dbg:
		print "\n***Graph State Transition Table*** \n"
		fout.write("\n***Graph State Transition Table*** \n")
		for indD in range (0, len(StateTrans)):
			print StateTrans[indD], "\n"
			fout.write(str(StateTrans[indD])+" \n")

	#if dbg: result = raw_input()


	# Create controller nodes
	for ind in range (0, len(States)):
		dStates.node(States[ind], States[ind], width='1',fontsize=NodeFontSizeLoop,shape='ellipse', rank='same') # color='red'

	# Create controller edges
	for ind in range (0, len(StateTrans)):
		EdgeOp = StateTrans[ind][2]+"/"+StateTrans[ind][3]+"/"+StateTrans[ind][4]+"/"+StateTrans[ind][5]

		# Only draw
		if ((DrawStalls!=0) or 								# Either draw stalls
			(StateTrans[ind][4]!="-") or 					# Check if some cesponse message exists
			(StateTrans[ind][5]!="-") or 					# Check if some internal op must be performed
			(StateTrans[ind][1] != StateTrans[ind][6])):	# Check if received message triggers state transition

			if StateTrans[ind][1] == StateTrans[ind][6]:
				dStates.edge(	StateTrans[ind][1],
								StateTrans[ind][6],
								EdgeOp,
								#tailport='ne',		# Possible to modify later and alternate if many loops exist
								fontsize=EdgeFontSizeLoop,
								fontcolor=lcolor,
								constraint='false')
			else:
				dStates.edge(	StateTrans[ind][1],
								StateTrans[ind][6],
								EdgeOp,
								fontsize=EdgeFontSizeInt,
								fontcolor=lcolor)

	return dStates

def Render_FSM_Graph(Graph):
	# Render controller FSM
	Graph.view()
	print(Graph.source)
	fout.write("\n***Graph Source*** \n")
	fout.write(str(Graph.source)+"\n\n\n\n")

	return 1




### Main Program startGet_Nested_Keys
print ("Python (Cache Coherence) Protocol Parser")

# Debug flag
dbg=1

# Key words for which it must be searched in text
# Message Type
MType = "MessageType"
# Cache Controller
CType="CacheStates"
CRecvFunc="L1CacheReceive"
CCPU="n:L1Cache"
# Directory Controller
DType="DirectoryState"
DRecvFunc="DirectoryReceive"


# General Keys
FuncKeys = ["function","procedure"]
FuncEndKey = ["end;"]
EnumKey = ["enum"]
DecsKey = ["case"]
SubDecsKey = ["if","endif","else"]
TransKey = [".state","Send(","return"]
RuleKey = ["rule"]
RuleEndKey =["endrule"]
RuleSetKey=["ruleset"]
RuleSetEndKey=["endruleset"]

# Sub keyword search region in lines after keyword was found
SubSR = 4

# Global Graph Options
DrawStalls=0;

EdgeFontSizeInt='10'
EdgeFontSizeLoop='8'
NodeFontSizeLoop='12'
TextFontSize='15'

CPUInitTrans='red'
MSGInitTrans='blue'

filename='VIW.m'

path = "PPP_"+filename.split(".", 1)[0]

file = open(filename).read().splitlines()

if not (os.path.isdir(path)):
	os.mkdir(path) 

os.chdir(path)

fout = open((filename+'.log'), 'w')

### Messages ###
# Extract message types
MTypes=Get_Msg_State_Type(file,MType,EnumKey[0],SubSR,dbg)
fout.write("\n"+"Number of $"+MType+ " declarations found: " +str(len(MTypes))+"\n")
fout.write(MType+"(s) \n")
for ind in range(0,len(MTypes)):
	fout.write(str(MTypes[ind])+"\n")
fout.write("\n\n")

### Cache Parsing ###
fout.write("### "+CType+" ###")
# Extract cache controller states
CStates=Get_Msg_State_Type(file,CType,EnumKey[0],SubSR,dbg)
fout.write("\n"+"Number of $"+CType+ " declarations found: " +str(len(CStates))+"\n")
fout.write(CType+"(s) \n")
for ind in range(0,len(CStates)):
	fout.write(str(CStates[ind])+"\n")
fout.write("\n\n")

start = Get_FSM_Function_Start(file,CRecvFunc,FuncKeys,SubSR,dbg)
end = Get_FSM_Function_End(file,FuncEndKey,start,dbg)
CStateTrans=Get_FSM_Transitions(file,start,end, MTypes, CStates, DecsKey, TransKey)
# Extract CPU Commands
start = Get_FSM_Function_Start(file,CCPU,RuleSetKey,1,dbg)
Region=Get_Nested_Keys(file,start,RuleSetKey,RuleSetEndKey)
CCPUTrans=Get_CPU_FSM_Transitions(file,Region[0][2],Region[len(Region)-1][2],RuleKey,RuleEndKey,MTypes,CStates,TransKey)


# Sort the state sequence based on number of Outputs, Inputs,
# AND reverse the sequences if necessary
# FOR NOW KEEP CPU TRANSACTIONS OUT OF GENERATION PROCESS, IT LOOKS BETTER.
# (CStateTrans+CCPUTrans)
TStates=Graph_State_Sort(CStates,(CStateTrans),0,1,0)

dCache=Create_FSM_Graph(CType,1)
dCache=Populate_FSM_Graph(dCache,TStates,CCPUTrans,CPUInitTrans)
dCache=Populate_FSM_Graph(dCache,[],CStateTrans,MSGInitTrans)
Render_FSM_Graph(dCache)


### Directory Parsing ###
#fout.write("### "+DType+" ###")
# Extract dirctory controller states
#DStates=Get_Msg_State_Type(file,DType,EnumKey[0],SubSR,dbg)
#fout.write("\n"+"Number of $"+DType+ " declarations found: " +str(len(DStates))+"\n")
#fout.write(DType+"(s) \n")
#for ind in range(0,len(DStates)):
#	fout.write(str(DStates[ind])+"\n")
#fout.write("\n\n")

### Directory Parsing ###
#start = Get_FSM_Function_Start(file,DRecvFunc,FuncKeys,SubSR,dbg)
#end = Get_FSM_Function_End(file,FuncEndKey,start,dbg)
#DStates=
#DStateTrans=Get_FSM_Transitions(file,start,end, MTypes, DStates, DecsKey, TransKey)

#TStates=Graph_State_Sort(DStates,DStateTrans,0,1,0)
#dDir=Create_FSM_Graph(DType,0)
#dDir=Populate_FSM_Graph(dDir,TStates,DStateTrans,MSGInitTrans)
#Render_FSM_Graph(dDir)



fout.write("PROGRAM END ")
