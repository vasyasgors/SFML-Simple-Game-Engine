# SFML Simple Game Engine
Простой игровой движок работающий с библиотекой SFML, предназначенный для создания более сложных игр в учебных целях. Движок построен по принципам Unity, и использует игровые объекты и комопненты для описания сцен игр. 

## Настройка
В настройках проекта:

Дополнительные каталоги включаемых фалов:
```
$(SolutionDir)SFML\include
$(SolutionDir)dev\engine\include
```
Дополнительные каталоги библиотек:
```
$(SolutionDir)SFML\lib
```
Дополнительные зависимости:
```
sfml-audio-d.lib
sfml-graphics-d.lib
sfml-main-d.lib
sfml-network-d.lib
sfml-network-s-d.lib
sfml-system-d.lib
sfml-system-s-d.lib
sfml-window-d.lib
sfml-window-s-d.lib
```
Последовательность компиляции файлов (Указывается в файле *.vcxproj)
```
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
```  
## Удобная работа
Чтобы при компиляции проекта исполняемые библиотеки SFML сами копировались в проект, нужно добавить все файлы из папки SFML->bin. Затем, в настройках каждого файла в пункте
"Тип элемента" выберите копирование. 
Копирование библиотек - включить в проект и в свойствах файла выбрать копирование

Все ресурсы игры рекомендуется поместить в папку resources. Для автоматического копирования этой папки в папку с готовой игрой, добавьте следующие строки в файл *.vcxproj.
```
<ItemGroup>
    <Content Include="resources\**">
      <CopyToOutputDirectory>PreserveNewest</CopyToOutputDirectory>
    </Content>
</ItemGroup>
```
