from pyautocad import Autocad, APoint


acad = Autocad(create_if_not_exists=True)
acad.prompt("Please wait as AutoCad opens....\n")
print(acad.doc.Name)
acad.model





mytupil = ((0, 0),(247.5, -190.5),(954.5, 269.5),(1298.5, -260.5),(1398.5, -360.5),(1178.5, -680.5),(360.5, -420.5),(280.5, -420.5),(247.5, -268.5),(1552.5, 269.5),(2474.5, -600.5),(2474.5, -680.5),(2494.5, 219.5),(2494.5, 139.5))

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
