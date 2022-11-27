make: main.cpp lib/CoffeeMachine.cpp lib/HumanInterface.cpp db/db.cpp lib/Service.cpp lib/Work.cpp
	g++ -o coffee main.cpp lib/CoffeeMachine.cpp lib/HumanInterface.cpp db/db.cpp lib/Service.cpp lib/Work.cpp
	./coffee