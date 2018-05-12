##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SquareWorld
ConfigurationName      :=Debug
WorkspacePath          :=/home/djm/Documentos/SFMLProjects
ProjectPath            :=/home/djm/Documentos/SFMLProjects/SquareWorld
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=DJM
Date                   :=11/05/18
CodeLitePath           :=/home/djm/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SquareWorld.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system $(LibrarySwitch)sfml-audio 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-system" "sfml-audio" "sfml-graphics" "sfml-window" "sfml-system" "sfml-audio" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/pixel.cpp$(ObjectSuffix) $(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix) $(IntermediateDirectory)/mainMenu.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/Documentos/SFMLProjects/SquareWorld/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/pixel.cpp$(ObjectSuffix): pixel.cpp $(IntermediateDirectory)/pixel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/Documentos/SFMLProjects/SquareWorld/pixel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pixel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pixel.cpp$(DependSuffix): pixel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pixel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pixel.cpp$(DependSuffix) -MM pixel.cpp

$(IntermediateDirectory)/pixel.cpp$(PreprocessSuffix): pixel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pixel.cpp$(PreprocessSuffix) pixel.cpp

$(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix): KEYBOARD.cpp $(IntermediateDirectory)/KEYBOARD.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/Documentos/SFMLProjects/SquareWorld/KEYBOARD.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/KEYBOARD.cpp$(DependSuffix): KEYBOARD.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/KEYBOARD.cpp$(DependSuffix) -MM KEYBOARD.cpp

$(IntermediateDirectory)/KEYBOARD.cpp$(PreprocessSuffix): KEYBOARD.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/KEYBOARD.cpp$(PreprocessSuffix) KEYBOARD.cpp

$(IntermediateDirectory)/mainMenu.cpp$(ObjectSuffix): mainMenu.cpp $(IntermediateDirectory)/mainMenu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/Documentos/SFMLProjects/SquareWorld/mainMenu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mainMenu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mainMenu.cpp$(DependSuffix): mainMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mainMenu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mainMenu.cpp$(DependSuffix) -MM mainMenu.cpp

$(IntermediateDirectory)/mainMenu.cpp$(PreprocessSuffix): mainMenu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mainMenu.cpp$(PreprocessSuffix) mainMenu.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


