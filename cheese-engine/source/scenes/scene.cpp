#include "scenes/scene.hpp"

/* Getters */

int& Scene::getID(){

    return m_ID;
}

std::string& Scene::getName(){

    return m_name;
}


/* Setters */

void Scene::setID( int id ){

    m_ID = id;
}

void Scene::setName( const char* name ){

    m_name = name;
}