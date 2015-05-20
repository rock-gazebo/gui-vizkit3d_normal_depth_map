/*
 * NormalDepthMap.h
 *
 *  Created on: Mar 27, 2015
 *      Author: tiagotrocoli
 */

#ifndef GUI_VIZKIT3D_NORMAL_DEPTH_MAP_SRC_NORMALDEPTHMAP_HPP_
#define GUI_VIZKIT3D_NORMAL_DEPTH_MAP_SRC_NORMALDEPTHMAP_HPP_

#include <osg/Node>
#include <osg/Group>
#include <osg/ref_ptr>

namespace vizkit3d_normal_depth_map {

/**
 * @brief Gets the informations of normal and depth from a osg scene, between the objects and the camera.
 *
 * Using a shaders render process, it is build a map with two values:
 *  The dot product with normal vector of the object surface and the camera normal vector, called normal value;
 *  The distance between the objects and the camera, called depth value;
 *
 */
class NormalDepthMap {
public:
    /**
     * @brief Build a map informations from the normal surface and depth from objects to the camera.
     *
     * This class takes a osg node scene and apply the shaders
     *  to get the depth and normal surface information between the
     *  camera and the objects in the scene.
     *
     *  Ths class apply the shaders to get the normal and depth information, to build the map in osg::Node.
     *  The normal values are in the blue color channel, where:
     *      1 is the max value, and represents the normal vector of the object surface and the normal vector of camera are in the same directions, || ;
     *      0 is the minimum value, the normal vector of the object surface and the normal vector of camera are in the perpendicular directions, |_ ;
     *  The depth values are in the green color channel, where:
     *      1 is the max value, and represents the object is near from the camera;
     *      0 is the minimum value, and represents the object is far from the camera;
     *
     *  @param maxRange: It is a float value which limits the depth calculation process. Default maxRange = 50.0
     */
    NormalDepthMap();
    NormalDepthMap(float maxRange);

    /**
     * @brief Add the models in the normal depth map node
     *  @param node: osg node to add a main scene
     */
    void addNodeChild(osg::ref_ptr<osg::Node> node);

    /**
     * @brief Get the node with the normal and depth map
     *  @param node: It is a node with the models in the target scene
     */
    const osg::ref_ptr<osg::Group> getNormalDepthMapNode() const {
        return _normalDepthMapNode;
    }

    void setMaxRange(float maxRange);
    float getMaxRange();

    void setDrawNormal(bool drawNormal);
    bool isDrawNormal();

    void setDrawDepth(bool drawDepth);
    bool isDrawDepth();

private:
    osg::ref_ptr<osg::Group> createTheNormalDepthMapShaderNode(float maxRange = 50.0, bool drawDepth = true, bool drawNormal = true);
    osg::ref_ptr<osg::Group> _normalDepthMapNode; //main shader node
};
}

#endif /* GUI_VIZKIT3D_NORMAL_DEPTH_MAP_SRC_NORMALDEPTHMAP_HPP_ */
