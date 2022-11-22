class Object {
    double x;
    double y;
    double z;
};

class Thing:Object {
    double strength;
    int condition = 100;
    void hit();
};

class Weapon:Thing {
    int damage;
    int price;
};

class EffectObject:Object {
    void effect();
};

class Food:EffectObject {
    int satietyfill;
    void eat();
};

class Mob:Object {
    int hp;
    int id;
    double speed;
    void hit();
};

class HostileMob:Mob {
    int damage;
    int targets_id[10];
};

class Person:Mob {
    char name[20];
    Weapon weapon;
    int satiety = 100;
};
