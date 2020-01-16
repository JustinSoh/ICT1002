def addData(userInput , currentList):
    strUserInput = str(userInput)
    currentList.append(strUserInput);
    return currentList;


x = 0
currentList = [];
while x != -1:
    print("What input value do you want? (-1 to exit)");
    x = raw_input();
    if x != -1:
        currentList = addData(x , currentList);
        print(currentList);
    else:
        print("Thanks for playing");
        print("Your current list is ");
        print(currentList);