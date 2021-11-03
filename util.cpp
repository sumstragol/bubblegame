//
//  util.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#include "util.hpp"

void util::load_tex(sf::Texture &tex, const std::string& path)
{
    tex.loadFromFile(path);
}
