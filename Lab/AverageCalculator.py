import sys;

if len(sys.argv) is not 4:
    print"Your input is invalid!";
else:
    try:
        a = float(sys.argv[1]);
        b = float(sys.argv[2]);
        c = float(sys.argv[3]);
        sum = a + b + c;
        length = len(sys.argv) - 1;
        average = sum / length;
        print("Average: %.2f" % average)
    except Exception:
        print("Your input is invalid!");