set Service = GetObject("winmgmts:root/wmi")
set EnumSet = Service.InstancesOf ("AcpiFirmwareCommunication")
for each Instance in EnumSet
  Wscript.Echo "Current  Val: " & Hex(instance.Command)
  instance.Command = 1
  instance.Put_()
  Wscript.Echo "Set New Val: " & Hex(instance.Command)
next 'instance