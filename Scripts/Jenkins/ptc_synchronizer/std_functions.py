import subprocess
import io
def run_command_str(commandStr):
    retStr = ''
    p = subprocess.Popen(commandStr, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    for line in io.TextIOWrapper(p.stdout, encoding="utf-8"):
        line = line.strip()
        if line:
            retStr += '{}\n'.format(line)

    for line in io.TextIOWrapper(p.stderr, encoding="utf-8"):
        line = line.strip()
        if line:
            retStr += '{}\n'.format(line)

    return retStr
