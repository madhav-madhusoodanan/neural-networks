from pyautocad import Autocad, Apoint

acad = Autocad()
p3 = Apoint(10, 10)
p4 = Apoint(10,50)
line1 = acad.model.AddLine(p3, p4)
line1.layer = 'longrebar'
