#include "Box2D/Box2D.h"
#include <cstdio>

int main(int argc, char *argv[]) {
    b2World world(b2Vec2(0.0f, -9.8f));

    //create the floor
    b2BodyDef floorDef;
    floorDef.position.Set(0.0f, -10.0f);
    b2Body* floor = world.CreateBody(&floorDef);
    b2PolygonShape floorShape;
    floorShape.SetAsBox(50.0f, 10.0f);
    floor->CreateFixture(&floorShape, 0.0f);

    //create a box floating above the floor
    b2BodyDef boxDef;
    boxDef.type = b2_dynamicBody;
    boxDef.position.Set(0.0f, 4.0f);
    b2Body* box = world.CreateBody(&boxDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(1.0f, 1.0f);
    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1.0f;
    boxFixtureDef.friction = 0.3f;
    box->CreateFixture(&boxFixtureDef);

    //run simulation
    printf("Simulating box falling\n");
    printf("Should stop approximately 1 unit above the ground\n");
    for (int i = 0; i < 60; i++) {
        world.Step(1.0f/60.0f, 6, 2);   //step by 1/60th of a second, 6 vel iterations, 2 pos iterations
        printf("%4.2f\t", box->GetPosition().y);
        if (i % 4 == 3 ) printf("\n");
    }

    //don't close cmd instantly
    system("pause");

    return 0;
}
