#include "World.h"

#include <map>
#include <string_view>

#include "Sphere.h"

Scene& getScene1()
{
    //Scene implicits
    constexpr glm::vec3 lookAt{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lookFrom{0.0f, 0.0f, 1.0f};
    constexpr glm::vec3 lookUp{0.0f, 1.0f, 0.0f};
    constexpr int fov {90};

    constexpr glm::vec3 lightDirection{0.0f, 1.0f, 0.0f};
    constexpr glm::vec3 lightColor{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 ambientColor{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 backgroundColor{0.2f, 0.2f, 0.2f};

    static Scene scene{lookAt, lookFrom, lookUp, fov, lightDirection, lightColor, ambientColor, backgroundColor};

    //Objects
    
    static Sphere spherePurple {{0.0f, 0.0f, 0.0f}, .4f, .7f, .2f,
        .1f, {1.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, 16.0f };

    scene.addObject(spherePurple);
    return scene;
}

Scene& getScene2()
{
    //Scene implicits
    constexpr glm::vec3 lookAt{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lookFrom{0.0f, 0.0f, 1.0f};
    constexpr glm::vec3 lookUp{0.0f, 1.0f, 0.0f};
    constexpr int fov {90};

    constexpr glm::vec3 lightDirection{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 lightColor{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 ambientColor{0.1f, 0.1f, 0.1f};
    constexpr glm::vec3 backgroundColor{0.2f, 0.2f, 0.2f};

    static Scene scene{lookAt, lookFrom, lookUp, fov, lightDirection, lightColor, ambientColor, backgroundColor};

    //Objects

    static Sphere sphereWhite {glm::vec3{0.45f, 0.0f, -0.15f}, .15f, .8f, .1f, .3f, glm::vec3{1.0f, 1.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f };
    static Sphere sphereRed {glm::vec3{0.0f, 0.0f, -0.1f}, .2f, .6f, .3f, .1f, glm::vec3{1.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 32.0f };
    static Sphere sphereGreen {glm::vec3{-0.6f, 0.0f, 0.0f}, .3f, .7f, .2f, .1f, glm::vec3{0.0f, 1.0f, 0.0f}, glm::vec3{0.5f, 1.0f, 0.5f}, 64.0f };
    static Sphere sphereBlue {glm::vec3{0.0f, -10000.5f, 0.0f}, 10000.0f, .9f, 0.0f, .1f, glm::vec3{0.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 16.0f };

    scene.addObject(sphereWhite);
    scene.addObject(sphereRed);
    scene.addObject(sphereGreen);
    scene.addObject(sphereBlue);
    return scene;
}

Scene& getScene3()
{
    //Scene implicits
    constexpr glm::vec3 lookAt{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lookFrom{0.0f, 0.0f, 1.0f};
    constexpr glm::vec3 lookUp{0.0f, 1.0f, 0.0f};
    constexpr int fov {90};

    constexpr glm::vec3 lightDirection{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 lightColor{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 ambientColor{0.1f, 0.1f, 0.1f};
    constexpr glm::vec3 backgroundColor{0.2f, 0.2f, 0.2f};

    static Scene scene{lookAt, lookFrom, lookUp, fov, lightDirection, lightColor, ambientColor, backgroundColor};

    //Objects

    static Sphere sphereWhite {glm::vec3{0.45f, 0.0f, -0.15f}, .15f, .8f, .1f, .3f, glm::vec3{1.0f, 1.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f };
    static Sphere sphereRed {glm::vec3{0.0f, 0.0f, -0.1f}, .2f, .6f, .3f, .1f, glm::vec3{1.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 32.0f };
    static Sphere sphereGreen {glm::vec3{-0.6f, 0.0f, 0.0f}, .3f, .7f, .2f, .1f, glm::vec3{0.0f, 1.0f, 0.0f}, glm::vec3{0.5f, 1.0f, 0.5f}, 64.0f };
    static Sphere sphereBlue {glm::vec3{0.0f, -10000.5f, 0.0f}, 10000.0f, .9f, 0.0f, .1f, glm::vec3{0.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 16.0f };

    scene.addObject(sphereWhite);
    scene.addObject(sphereRed);
    scene.addObject(sphereGreen);
    scene.addObject(sphereBlue);
    return scene;
}

const std::map<std::string_view, Scene>& getScenes()
{
    static std::map<std::string_view, Scene> scenes {{"scene1", getScene1()}, {"scene2", getScene2()}, {"scene3", getScene3()}};

    return scenes;
}