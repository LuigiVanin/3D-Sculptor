# Escultor 3D em C++

--- 

Esse projeto consiste na criação de um escultor 3D interativo que gera figuras baseadas em cubos, criando sólidos similares a algo visto no jogo *minecraft*. O código desse projeto é desenvolvido inteiramenta em **C++** utilizarando primariamente o estilo de programação orientado a objeto(POO). 

Além da linguagem de programação C++, outras ferramentas para a vizualização das figuras geradas devem ser utilizadas, as recomendações são o **geomview** ou **meshlab**. Os softwares previamente citados foram escolhidos, pois possuem a capacidade de ler e representar arquivos do tipo **.OFF** que é o tipo de arquivo utilizado para se armazenar os sólidos feitos pelo programa em C++. 

<br>

<p align="center">
  <img src= "./assets/ezgif.com-gif-maker.gif" height = 350/ width = 350>
</p>

O desenvolvimento desse projeto consistirá em duas etapas, sendo elas:

- **ETAPA 1** - desenvolvimento das ferramentas de desenho 3D.
- **ETAPA 2** - Criação de uma ferramenta interativa.

## Estrutura

O código é fragmentado em dois diretórios principais e um código "main.cpp". Os diretótios são responsáveis por armazenas os cabeçalhos e classes C++. Os diretórios utilizados são os seguintes:

- **include** - retém os cabaçalhos(.hpp) da classe Sculptor e do Struct Voxel. A classe Sculptor é definido no arquivo Sculptor.cpp.

- **src** - 

## Código

<p>
 O escultor 3D será, basicamente, uma matriz tridimensional a qual cada um de seus espaços contém um objeto do tipo "Voxel" que é uma representação de uma unidade de epaço 3D similar ao pixel no espaço 2D. A classe respectiva ao Voxel possui os atributos de cor RGB dados na forma de float e uma booleana que diz se o respectivo voxel está sólido ou não. Abaixo o código para o voxel:
 </p>

~~~cpp
struct Voxel {
  float r,g,b; // Cores
  float a; // trasparência

  bool isOn; // solidez do voxel
};
~~~