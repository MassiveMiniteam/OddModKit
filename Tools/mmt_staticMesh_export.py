import bpy
import os
import numpy
selObj = bpy.context.selected_objects

ApplyTransforms=True

for i in range(len(bpy.context.selected_objects)):
    
    obj = selObj[i]
    old_parent = obj.parent
    
    # select object
    bpy.ops.object.select_all(action='DESELECT')
    bpy.data.objects[obj.name].select_set(True)

    # clear parent
    bpy.ops.object.parent_clear(type='CLEAR')

    # position at origin
    locationX = bpy.context.object.location[0]
    locationY = bpy.context.object.location[1]
    locationZ = bpy.context.object.location[2]
    
    if ApplyTransforms:
        bpy.ops.object.transform_apply(location=True, rotation=False, scale=False)
        
    else:
        bpy.context.object.location[0] = 0
        bpy.context.object.location[1] = 0
        bpy.context.object.location[2] = 0

    # export
    # look for export path
    basedir = os.path.dirname(bpy.data.filepath)
    dirSplit = os.path.split(basedir)
    print(basedir)
    print(dirSplit)
    
    # search for Export folder
    exportStr = "Export"
    if os.path.exists(os.path.join(basedir, exportStr)):
        exportDir = os.path.join(basedir, exportStr)
        
    elif os.path.exists(os.path.join(dirSplit[0], exportStr)):
        exportDir = os.path.join(dirSplit[0], exportStr)

    else:
        dirSplit = os.path.split(dirSplit[0])
        if os.path.exists(os.path.join(dirSplit[0], exportStr)):
            exportDir = os.path.join(dirSplit[0], exportStr)
        else:
            exportDir = basedir

    # create new filename
    objName = bpy.path.clean_name(obj.name)

    if not objName.startswith("S_"):
        self.report({"WARNING"}, "Please rename object with prefix 'S_'")
        
    fn = os.path.join(exportDir, objName)
    bpy.ops.export_scene.fbx(filepath=fn + ".fbx", use_selection=True, object_types={'MESH'}, bake_anim=False)

    # reset object position
    if ApplyTransforms:
        bpy.context.object.location[0] = locationX*-1
        bpy.context.object.location[1] = locationY*-1
        bpy.context.object.location[2] = locationZ*-1
        
        bpy.ops.object.transform_apply(location=True, rotation=False, scale=False)
        
        bpy.context.object.location[0] = locationX
        bpy.context.object.location[1] = locationY
        bpy.context.object.location[2] = locationZ
            
    else:
        bpy.context.object.location[0] = locationX
        bpy.context.object.location[1] = locationY
        bpy.context.object.location[2] = locationZ
    
    # reset parent
    bpy.ops.object.select_all(action='DESELECT')
    
    obj.parent = old_parent
