###########################
##  PYTHON & CAPL TEST  ###
###########################
from __future__ import print_function
import isystem.connect as ic
import time


class Parser:

    def __init__(self, input_path, output_path):
        self.fin = open(input_path, "r+")
        self.fout = open(output_path, "w")
        self.content = self.fin.readlines()

    def parse_line(self, commands, line):
        for key in commands:
            commands[key][1].clear()
        try:
            self.row = self.content[line].replace('\n', '')
            self.row = self.row.replace("=", "")
            self.column = self.row.split(' ')

            # if the item at the given index of coulmn array does not exist it will throw an IndexError to end the while loop #
            self.counter = 0
            for param in self.column:
                if self.counter > 0:
                    commands[self.column[0]][1].append(param)  # self.column[self.counter])
                self.counter += 1
            self.error = "No error"
        except IOError:
            self.error = "IO exception error"
        except IndexError:
            # TO DO #
            # Print some info regarding this exception #
            pass

    def debugger_instructions(self, commands):
        # iterator = 1
        iterator = 0
        self.parse_line(commands, iterator)
        size = len(self.content)
        print( f"{self.content}")
        while iterator < size:
            if self.column[0] in commands:
                # self.column[0] -> used as a key for the commands{} dictionary (e.g. 'set_bp') #
                # value of dictionary is and aray with a function and another array #
                # the second array represents the parameters for the function #
                self.fout.write(f"{commands[self.column[0]][0](*commands[self.column[0]][1])}\n")
                # self.fout.write(f"{commands[self.column[0]][0](*commands[self.column[0]][1])}\n")
                iterator += 1
            else:
                self.fout.write("Not Existent\n")
                iterator += 1
            self.parse_line(commands, iterator)
            time.sleep(0.001)
        self.fin.close()

