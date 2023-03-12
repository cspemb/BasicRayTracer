#include "World.h"

#include <map>
#include <memory>
#include <string_view>

#include "LambertianMaterial.h"
#include "ReflectiveMaterial.h"
#include "Sphere.h"
#include "Triangle.h"

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

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, 0.0f, 0.0f}, .4f,
        std::make_shared<LambertianMaterial>(.7f, .2f, .1f,
            glm::vec3{1.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 16.0f)
));
    
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

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.45f, 0.0f, -0.15f}, .15f,
        std::make_shared<LambertianMaterial>(.8f, .1f, .3f,
            glm::vec3{1.0f, 1.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f )));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, 0.0f, -0.1f}, .2f,
        std::make_shared<LambertianMaterial>(.6f, .3f, .1f,
            glm::vec3{1.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 32.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{-0.6f, 0.0f, 0.0f}, .3f,
        std::make_shared<LambertianMaterial>(.7f, .2f, .1f,
            glm::vec3{0.0f, 1.0f, 0.0f}, glm::vec3{0.5f, 1.0f, 0.5f}, 64.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, -10000.5f, 0.0f}, 10000.0f,
        std::make_shared<LambertianMaterial>(.9f, 0.0f, .1f,
            glm::vec3{0.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 16.0f) ));

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
    
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-20.0f, 10.0f, -10.0f}, 10.0f,
        std::make_shared<LambertianMaterial>(.55f, .35f, .1f,
            glm::vec3{1.0f, 0.75f, 0.75f}, glm::vec3{1.0f, 0.5f, 0.5f}, 32.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{1.0f, 2.5f, -1.0f}, 0.03f,
        std::make_shared<LambertianMaterial>(.8f, .1f, .1f,
            glm::vec3{0.93f, 0.45f, 0.65f}, glm::vec3{1.0f, 0.7f, 0.7f}, 15.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, 1.5f, -2.0f}, 0.15f,
        std::make_shared<LambertianMaterial>(.9f, 0.0f, .1f,
            glm::vec3{0.8f, 0.15f, 0.05f}, glm::vec3{0.7f, 1.0f, 0.7f}, 7.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{-2.0f, 3.5f, -3.0f}, 0.5f,
        std::make_shared<LambertianMaterial>(.4f, .4f, .2f,
            glm::vec3{0.7f, 0.75f, 0.65f}, glm::vec3{0.7f, 0.7f, 1.0f}, 64.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{-4.0f, 0.5f, -0.5f}, 0.8f,
        std::make_shared<LambertianMaterial>( .3f, .1f, .6f,
            glm::vec3{0.3f, 0.35f, 0.35f}, glm::vec3{0.3f, 0.5f, 0.5f}, 8.0f)));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{-5.0f, 0.0f, 1.0f}, 1.2f,
        std::make_shared<LambertianMaterial>(.9f, 0.0f, .1f,
            glm::vec3{0.07f, 0.07f, 0.07f}, glm::vec3{1.0f, 1.0f, 1.0f}, 22.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{-12.0f, 5.0f, -18.0f}, 7.5f,
        std::make_shared<LambertianMaterial>(.5f, .4f, .1f,
            glm::vec3{0.9f, 0.85f, 0.75f}, glm::vec3{.05f, .05f, .05f}, 11.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{-101.0f, 100.0f, -200.0f}, 115.0f,
        std::make_shared<LambertianMaterial>(.2f, .4f, .4f,
            glm::vec3{0.2f, 0.65f, 0.65f}, glm::vec3{0.86f, 0.5f, 0.95f}, 48.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{-4.0f, -3.5f, -13.0f}, 2.5f,
        std::make_shared<LambertianMaterial>(.5f, .3f, .2f,
            glm::vec3{0.75f, 0.6f, 0.75f}, glm::vec3{.3f, .3f, .3f}, 17.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{1.0f, 0.5f, -1.0f}, 0.3f,
        std::make_shared<LambertianMaterial>(.75f, .2f, .05f,
            glm::vec3{0.1f, 0.75f, 0.75f}, glm::vec3{0.25f, 0.85f, 0.25f}, 1.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{2.0f, -0.5f, 0.0f}, 0.3f,
        std::make_shared<LambertianMaterial>(.8f, .1f, .1f,
            glm::vec3{0.75f, 0.75f, 0.1f}, glm::vec3{0.3f, 0.3f, 0.3f}, 1.0f) ));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{1.0f, 0.5f, -1.0f}, 0.3f,
        std::make_shared<LambertianMaterial>(.6f, .3f, .1f,
            glm::vec3{0.2f, 0.45f, 0.65f}, glm::vec3{0.7f, 0.7f, 0.7f}, 27.0f) ));
    
    return scene;
}

Scene& getScene4()
{
    //Scene implicits
    constexpr glm::vec3 lookAt{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lookFrom{0.0f,  0.0f, 1.0f};
    constexpr glm::vec3 lookUp{0.0f, 1.0f, 0.0f};
    constexpr int fov {90};

    constexpr glm::vec3 lightDirection{0.0f, 1.0f, 0.0f};
    constexpr glm::vec3 lightColor{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 ambientColor{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 backgroundColor{0.2f, 0.2f, 0.2f};

    static Scene scene{lookAt, lookFrom, lookUp, fov, lightDirection, lightColor, ambientColor, backgroundColor};

    //Objects
    
    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.0f, 0.3f, -1.0f}, .25f,
        std::make_shared<ReflectiveMaterial>(.0f, .1f, .1f,
            glm::vec3{.75f, 0.75f, 0.75f}, glm::vec3{1.0f, 1.0f, 1.0f}, 10.0f, .9f)));

    scene.addObject(std::make_shared<Triangle>(
       glm::vec3{0.0f, -0.7f, -0.5f},
       glm::vec3{1.0f, 0.4f, -1.0f},
       glm::vec3{0.0f, -0.7f, -1.5f},
       std::make_shared<LambertianMaterial>(.9f, 1.0f, .1f,
       glm::vec3{0.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f ))
       );

    scene.addObject(std::make_shared<Triangle>(
        glm::vec3{0.0f, -0.7f, -0.5f},
       glm::vec3{0.0f, -0.7f, -1.5f},
       glm::vec3{-1.0f, 0.4f, -1.0f},
       std::make_shared<LambertianMaterial>(.9f, 1.0f, .1f,
       glm::vec3{1.0f, 1.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f ))
       );
    
    return scene;
}

Scene& getScene5()
{
    //Scene implicits
    constexpr glm::vec3 lookAt{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lookFrom{0.0f,  0.0f, 1.0f};
    constexpr glm::vec3 lookUp{0.0f, 1.0f, 0.0f};
    constexpr int fov {90};

    constexpr glm::vec3 lightDirection{1.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lightColor{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 ambientColor{0.1f, 0.1f, 0.1f};
    constexpr glm::vec3 backgroundColor{0.2f, 0.2f, 0.2f};

    static Scene scene{lookAt, lookFrom, lookUp, fov, lightDirection, lightColor, ambientColor, backgroundColor};

    //Objects

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.5f, 0.0f, -0.15f}, .05f,
    std::make_shared<LambertianMaterial>(.8f, .1f, .3f,
        glm::vec3{1.0f, 1.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f )));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.3f, 0.0f, -0.1f}, .08f,
    std::make_shared<LambertianMaterial>(.8f, .8f, .1f,
        glm::vec3{1.0f, 0.0f, 0.0f}, glm::vec3{.5f, 1.0f, 0.5f}, 32.0f )));
    
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-0.6f, 0.0f, -0.0f}, .3f,
        std::make_shared<LambertianMaterial>(.7f, .5f, .1f,
            glm::vec3{0.0f, 1.0f, 0.0f}, glm::vec3{.5f, 1.0f, 0.5f}, 64.0f )));

    scene.addObject(std::make_shared<Sphere>(glm::vec3{0.1f, -0.55f, 0.25f}, .3f,
    std::make_shared<ReflectiveMaterial>(.0f, .1f, .1f,
        glm::vec3{0.75f, .75f, 0.75f}, glm::vec3{1.0f, 1.0f, 1.0f}, 10.0f, .9f)));

    scene.addObject(std::make_shared<Triangle>(
        glm::vec3{0.3f, -0.3f, -0.4f},
       glm::vec3{0.0f, 0.3f, -0.1f},
       glm::vec3{-0.3f, -0.3f, 0.2f},
       std::make_shared<LambertianMaterial>(.9f, .9f, .1f,
       glm::vec3{0.0f, 0.0f, 1.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 32.0f ))
       );

    scene.addObject(std::make_shared<Triangle>(
        glm::vec3{-0.2f,0.1f, 0.1f},
       glm::vec3{-0.2f, -0.5f, 0.2f},
       glm::vec3{-0.2f, 0.1f, -0.3f},
       std::make_shared<LambertianMaterial>(.9f, .5f, .1f,
       glm::vec3{1.0f, 1.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}, 4.0f ))
       );
    
    return scene;
}

Scene& getScene6()
{
    //Scene implicits
    constexpr glm::vec3 lookAt{0.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lookFrom{0.0f,  0.0f, 1.0f};
    constexpr glm::vec3 lookUp{0.0f, 1.0f, 0.0f};
    constexpr int fov {90};

    constexpr glm::vec3 lightDirection{1.0f, 0.0f, 0.0f};
    constexpr glm::vec3 lightColor{1.0f, 1.0f, 1.0f};
    constexpr glm::vec3 ambientColor{0.1f, 0.1f, 0.1f};
    constexpr glm::vec3 backgroundColor{0.2f, 0.2f, 0.2f};

    static Scene scene{lookAt, lookFrom, lookUp, fov, lightDirection, lightColor, ambientColor, backgroundColor};

    //Objects
    
    scene.addObject(std::make_shared<Sphere>(glm::vec3{-20.0f, 10.0f, -10.0f}, 10.0f,
    std::make_shared<LambertianMaterial>(.55f, .35f, .1f,
        glm::vec3{1.0f, 0.75f, 0.75f}, glm::vec3{1.0f, 0.5f, 0.5f}, 32.0f)));
    
    return scene;
}

const std::map<std::string_view, Scene>& getScenes()
{
    static std::map<std::string_view, Scene> scenes {{"scene1", getScene1()}, {"scene2", getScene2()},
        {"scene3", getScene3()}, {"scene4", getScene4()}, {"scene5", getScene5()}, {"scene6", getScene6()}};
    
    return scenes;
}