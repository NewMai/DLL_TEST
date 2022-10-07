
import sys

def MyPrint(msg):
    print(msg)

def GenFunc(maxNum, name):
    dot_cpp  = "math.cpp"
    dot_h    = "math.h"
    dot_def  = "math.def"
    dll_name = "matn.dll"

    dot_cpp  = "%s.cpp" % (name)
    dot_h    = "%s.h" % (name)
    dot_def  = "%s.def" % (name)
    dll_name = "%s.dll" % (name)

    i = 0
    func_imp = ""
    func_dec = ""
    func_name = ""
    line = ""

    with open(dot_cpp, "w") as fw_cpp:
        with open(dot_h, "w") as fw_h:
            with open(dot_def, "w") as fw_def:

                line = "#include \"%s\"\n" % (dot_h)
                fw_cpp.write(line)

                line = "LIBRARY %s\n" % (dll_name)
                fw_def.write(line)
                line = "EXPORTS\n"
                fw_def.write(line)

                for i in range(0, maxNum):
                    func_name = "test_func_%d" % (i)
                    func_dec = "int %s(int a, int b);" % (func_name)
                    func_imp = "int %s(int a, int b) { return a + b; }" % (func_name)
                    line = "%s\n" % (func_imp)
                    fw_cpp.write(line)
                    line = "%s\n" % (func_dec)
                    fw_h.write(line)
                    line = "    %s\n" % (func_name)
                    fw_def.write(line)
                pass
            pass
        pass
    pass

def Main():
    maxNum = 2
    name = "test_dll"
    maxNum = 65535
    name = "test_max_export"
    if len(sys.argv) >= 2:
        a1 = sys.argv[1]
        maxNum = int(a1)
    if len(sys.argv) >= 3:
        a2 = sys.argv[2]
        name = a2
    MyPrint("Generate [%s] export functions for module [%s]!" % (maxNum, name))
    GenFunc(maxNum, name)
    MyPrint("Finished!")
    pass

Main()

