Дополнительные каталоги включаемых фалов:
$(SolutionDir)SFML\include

Дополнительные каталоги библиотек:
$(SolutionDir)SFML\lib

Дополнительные зависимости:
sfml-audio-d.lib
sfml-graphics-d.lib
sfml-main-d.lib
sfml-network-d.lib
sfml-network-s-d.lib
sfml-system-d.lib
sfml-system-s-d.lib
sfml-window-d.lib
sfml-window-s-d.lib

Проверочный код:
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

<ItemGroup>
    <ClCompile Include="dev\engine\src\components\Component.cpp" />
    <ClCompile Include="dev\engine\src\components\Renderer.cpp" />
    <ClCompile Include="dev\engine\src\components\SpriteRenderer.cpp" />
    <ClCompile Include="dev\engine\src\components\Behaviour.cpp" />
    <ClCompile Include="dev\engine\src\components\TextRenderer.cpp" />
    <ClCompile Include="dev\engine\src\GameObject.cpp" />
    <ClCompile Include="dev\engine\src\Scene.cpp" />
    <ClCompile Include="dev\game\include\constants.h" />
    <ClCompile Include="dev\game\src\main.cpp" />
    <ClCompile Include="dev\game\src\PlayerMovement.cpp" />
    <ClCompile Include="dev\engine\src\components\RectCollider.cpp" />
    <ClCompile Include="dev\engine\src\Game.cpp" />
  </ItemGroup>
  

Копирование библиотек - включить в проект и в свойствах файла выбрать копирование

<ItemGroup>
    <Content Include="resources\**">
      <CopyToOutputDirectory>PreserveNewest</CopyToOutputDirectory>
    </Content>
  </ItemGroup>

