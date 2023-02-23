#include "World.h"

#include <map>
#include <memory>
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

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, 0.0f, 0.0f}, .4f, .7f, .2f,
        .1f, glm::vec3{1.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 16.0f));
    
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

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.45f, 0.0f, -0.15f}, .15f, .8f, .1f, .3f, glm::vec3{1.0f, 1.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, 0.0f, -0.1f}, .2f, .6f, .3f, .1f, glm::vec3{1.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 32.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-0.6f, 0.0f, 0.0f}, .3f, .7f, .2f, .1f, glm::vec3{0.0f, 1.0f, 0.0f}, glm::vec3{0.5f, 1.0f, 0.5f}, 64.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, -10000.5f, 0.0f}, 10000.0f, .9f, 0.0f, .1f, glm::vec3{0.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 16.0f ));

    return scene;
}

Scene& getScene3()
{
    //Scene implicits
    constexpr glm::vec3 lookAt{1.0f, 1.0f, -1.0f};
    constexpr glm::vec3 lookFrom{3.0f,  0.0f, 1.0f};
    constexpr glm::vec3 lookUp{1.0f, 1.0f, 0.0f};
    constexpr int fov {70};

    constexpr glm::vec3 lightDirection{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 lightColor{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 ambientColor{0.1f, 0.1f, 0.1f};
    constexpr glm::vec3 backgroundColor{0.2f, 0.2f, 0.2f};

    static Scene scene{lookAt, lookFrom, lookUp, fov, lightDirection, lightColor, ambientColor, backgroundColor};

    //Objects
    
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-20.0f, 10.0f, -10.0f}, 10.0f, .55f, .35f, .1f, glm::vec3{1.0f, 0.75f, 0.75f}, glm::vec3{1.0f, 0.5f, 0.5f}, 32.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{1.0f, 2.5f, -1.0f}, 0.03f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, 1.5f, -2.0f}, 0.15f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-2.0f, 3.5f, -3.0f}, 0.5f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-4.0f, 0.5f, -0.5f}, 0.8f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-5.0f, 0.0f, 1.0f}, 1.2f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-12.0f, 5.0f, -18.0f}, 7.5f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-101.0f, 100.0f, -200.0f}, 115.0f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-4.0f, -3.5f, -13.0f}, 2.5f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{1.0f, 0.5f, -1.0f}, 0.3f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{2.0f, -0.5f, 0.0f}, 0.3f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    scene.addObject(std::make_shared<Sphere>(glm::vec3{1.0f, 0.5f, -1.0f}, 0.3f, .8f, .1f, .1f, glm::vec3{0.3f, 0.45f, 0.65f}, glm::vec3{0.3f, 0.5f, 0.5f}, 3.0f ));
    
    return scene;
}

const std::map<std::string_view, Scene>& getScenes()
{
    static std::map<std::string_view, Scene> scenes {{"scene1", getScene1()}, {"scene2", getScene2()}, {"scene3", getScene3()}};

    return scenes;
}