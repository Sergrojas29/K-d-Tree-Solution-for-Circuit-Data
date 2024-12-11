from pyautocad import Autocad, APoint


acad = Autocad(create_if_not_exists=True)
acad.prompt("Please wait as AutoCad opens....\n")
print(acad.doc.Name)
acad.model





mytupil = ((1550, 1300),(1762.71, 1187.55),(1782.56, 1827.89),(925.028, 2027.75),(808.805, 1580.57),(749.126, 1190.92),(657.892, 1692.55),)

def Points_To_Circle(mytupil , radiusOfCircle):
    for i in range(len(mytupil)):
        x,y = mytupil[i][0],mytupil[i][1]
        p1 = APoint(x,y)
        acad.model.AddCircle(p1,radiusOfCircle)

    
def Points_To_lines(mytupil):
    for i in range(len(mytupil)-1):
        x = mytupil[i][0]
        y = mytupil[i][1]
        
        x2 = mytupil[i+1][0]
        y2 = mytupil[i+1][1]
        
        p1 = APoint(x,y)
        p2 = APoint(x2,y2)
        
        acad.model.Addline(p1,p2)
    

Points_To_Circle(mytupil, 25)
Points_To_lines(mytupil)
