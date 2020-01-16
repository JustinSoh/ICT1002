# # First take in input for the first

# # Get the operator
# # If operator is not + , - , * , / then ask user to re enter value
def checkOperator(operatorVar):
    try:
        # operatorVar = raw_input('Please input your operator (+ , -  , * , / )');
        # only accepts + , / , * , -
        if str(operatorVar) == "+" or str(operatorVar) == "/" or str(operatorVar) == "*" or str(operatorVar) == "-":
            return True;
    except:
        print("Operator Invalid");
        return False



def checkInput(inputVar):
    canSplit = False;
    try:
        data = inputVar.split()
        for x in data:
            if data.index(x) % 2 == 0:
                # print("this is variable" + str(x))
                isNum = x.isdigit();
                if isNum == False:
                    return False;
                    exit();
            else:
                # print("this is operator" + str(x))
                isOperator = checkOperator(x);
                if isOperator == False:
                    return False;
                    exit();
            return(True);

    except Exception:
        print("Input Validation Failed");



def getInputCalculation():
    x = 0;
    while x is not -1:
        try:
            inputVar = raw_input("Input the calculation that you want: ");
            canCompute = checkInput(str(inputVar));
            if canCompute == True:
                x = -1;
                data = inputVar.split();
                
            else:
                print("Input is invalid");
        except:
            print("Invalid Input, try again");



getInputCalculation();
