import bpy
import os
import numpy

old_unit_scale = bpy.context.scene.unit_settings.scale_length
scale_factor = 100
scale_factor_reset = 1/scale_factor
selObj = bpy.context.selected_objects


# adjust location keyframes to scale for all actions
obj = bpy.context.active_object
loc = "location"

for action in bpy.data.actions:
    for c in action.fcurves:
        if c.data_path == loc:
            keyframes = c.keyframe_points
            for kf in keyframes:
                newY = kf.co.y * scale_factor
                kf.co.y = newY
                kf.handle_left[1] = newY
                kf.handle_right[1] = newY


# set unit scale
bpy.context.scene.unit_settings.scale_length = 0.01


for i in range(len(bpy.context.selected_objects)):
        
    obj = selObj[i]
    old_parent = obj.parent
    
    # select object
    bpy.ops.object.select_all(action='DESELECT')
    bpy.data.objects[obj.name].select_set(True)
    print("new")
    print(obj.name)
    print(bpy.context.object.name)

    # clear parent
    bpy.ops.object.parent_clear(type='CLEAR')

    #scale x100
    
    obj.scale[0] = scale_factor
    obj.scale[1] = scale_factor
    obj.scale[2] = scale_factor

    # apply scale
    bpy.ops.object.transform_apply(location=False, rotation=False, scale=True)
    
    
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

    if objName.startswith("S_"):
        newName = objName.replace(objName[0], "A", 1)
    else:
        newName = objName

    fn = os.path.join(exportDir, newName)
    bpy.ops.export_scene.fbx(filepath=fn + ".fbx", use_selection=True, bake_anim_simplify_factor=0.0,
    bake_anim_use_nla_strips=True, bake_anim_use_all_actions=False, object_types={'MESH', 'ARMATURE'})
    
    # reset parent
    ob_matrix_orig = obj.matrix_world.copy()
    # Reset parent inverse matrix
    obj.matrix_parent_inverse.identity()
    
    obj.parent = old_parent
    
    """if obj.parent:
        print(ob_matrix_orig)
        obj.matrix_basis = obj.parent.matrix_local.inverted() @ ob_matrix_orig"""
    
    # reset object scale
    obj.scale[0] = scale_factor_reset
    obj.scale[1] = scale_factor_reset
    obj.scale[2] = scale_factor_reset
    bpy.ops.object.transform_apply(location=False, rotation=False, scale=True)


# reset location keyframes scale
for action in bpy.data.actions:
    for c in action.fcurves:
        if c.data_path == loc:
            keyframes = c.keyframe_points
            for kf in keyframes:
                newY = kf.co.y * scale_factor_reset
                kf.co.y = newY
                kf.handle_left[1] = newY
                kf.handle_right[1] = newY
            
# reset unit scale
bpy.context.scene.unit_settings.scale_length = old_unit_scale