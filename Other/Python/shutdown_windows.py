# A script that asks the user for a time in minutes and executes timed Windows shutdown command.
# The script only allows integer inputs. Entering 0 cancels the ongoing timed shutdown.
# WARNING: The script executes forced shutdown, which might cause loss of unsaved data.

import os

shutdown_final = "shutdown.exe /s /f /t {}"
shutdown_cancel = "shutdown.exe /a"

txt_input = "Minutes to shutdown:"
txt_success_shutdown = "\nTimed shutdown was set successfully."
txt_success_cancel = "\nTimed shutdown was cancelled successfully."
txt_error = "\nThe minimum shutdown time is 1 minute.\nEntering 0 cancels the ongoing timed shutdown\nInteger is the only allowed input type.\n"

while True:
    valueerrorcheck = False
    try:
        shutdown_min = int(input(txt_input))
    except ValueError:
        valueerrorcheck = True
        print(txt_error)
    else:
        if shutdown_min == 0:
            os.system(shutdown_cancel)
            print(txt_success_cancel)
        else:
            os.system(shutdown_final.format(shutdown_min * 60))
            print(txt_success_shutdown)
        break
        
    if shutdown_min < 0 and not valueerrorcheck:
        print(txt_error)

os.system("pause")