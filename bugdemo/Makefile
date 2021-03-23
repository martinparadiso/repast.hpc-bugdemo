
MPICXX=mpicxx -std=c++11 

BOOST_INCLUDE=-I$(HOME)/sfw/Boost/Boost_1.61/include/
BOOST_LIB_DIR=-L$(HOME)/sfw/Boost/Boost_1.61/lib/
BOOST_LIBS=-lboost_mpi-mt -lboost_serialization-mt -lboost_system-mt -lboost_filesystem-mt

REPAST_HPC_INCLUDE=-I$(HOME)/sfw/repast_hpc-2.3.1/include/
REPAST_HPC_LIB_DIR=-L$(HOME)/sfw/repast_hpc-2.3.1/lib/
REPAST_HPC_LIB=-lrepast_hpc-2.3.1

.PHONY: bugdemo
bugdemo: 
	$(MPICXX) $(REPAST_HPC_DEFINES) $(BOOST_INCLUDE) $(REPAST_HPC_INCLUDE) -I./include -c ./src/Demo_03_Main.cpp -o ./build/main.o
	$(MPICXX) $(REPAST_HPC_DEFINES) $(BOOST_INCLUDE) $(REPAST_HPC_INCLUDE) -I./include -c ./src/Demo_03_Model.cpp -o ./build/model.o
	$(MPICXX) $(REPAST_HPC_DEFINES) $(BOOST_INCLUDE) $(REPAST_HPC_INCLUDE) -I./include -c ./src/Demo_03_Agent.cpp -o ./build/agent.o
	$(MPICXX) $(BOOST_LIB_DIR) $(REPAST_HPC_LIB_DIR) -o ./build/demo  ./build/main.o ./build/model.o ./build/agent.o $(REPAST_HPC_LIB) $(BOOST_LIBS)


