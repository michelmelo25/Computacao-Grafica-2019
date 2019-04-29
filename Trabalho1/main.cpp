#include <iostream>
#include <fstream>

using namespace std;

//#include <gui.h>
#include <vector>

//Import dos objedos a serem desenhador (arquivos .h)
#include <objeto.h>
#include <casa.h>
#include <predio.h>
#include <asfalto.h>
#include <arvore.h>
#include <loja.h>
#include <ambulancia.h>
#include <caminhao.h>
#include <dirigivel.h>

vector<string> nomesObj;
vector<Objeto*> objetos;
int posSelecionado = -1;

void desenha() {
    GUI::displayInit();

    GUI::setLight(1,1,3,5,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);
    //GUI::setLight(3,-5,3,5,true,false);

    GUI::drawOrigin(1);
    GUI::setColor(0,0,0);
    Desenha::drawGrid(10,0,7,1);
    GUI::setColor(1,0,0);
    GUI::drawFloor(20,14);
    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }
    glutGUI::dtx = 0.0; glutGUI::dty = 0.0; glutGUI::dtz = 0.0;
    glutGUI::dax = 0.0; glutGUI::day = 0.0; glutGUI::daz = 0.0;
    glutGUI::dsx = 0.0; glutGUI::dsy = 0.0; glutGUI::dsz = 0.0;

    GUI::displayEnd();
}

void iniciarVectror(){
    nomesObj.push_back("Predio");
    nomesObj.push_back("Casa");
    nomesObj.push_back("Asfalto");
    nomesObj.push_back("Caminhao");
    nomesObj.push_back("Dirigivel");
    nomesObj.push_back("Loja");
    nomesObj.push_back("Arvore");
    nomesObj.push_back("Ambulancia");
}

void gerarObj(string nome, GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool selecionado, bool eixo){
        if(nome == "Predio"){
            objetos.push_back(new Predio());
            objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
             cout << "Predio carregado" << endl;
        }else if(nome == "Ambulancia"){
            objetos.push_back(new Ambulancia());
             objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
            cout << "Ambulancia carregada" << endl;
        }else if(nome == "Casa"){
            objetos.push_back(new Casa());
             objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
            cout << "Casa carregada" << endl;
        }else if(nome == "Asfalto"){
            objetos.push_back(new Asfalto());
             objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
            cout << "Asfalto carregado" << endl;
        }else if(nome == "Caminhao"){
            objetos.push_back(new Caminhao());
             objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
            cout << "Caminhao carregado" << endl;
        }else if(nome == "Dirigivel"){
            objetos.push_back(new Dirigivel());
             objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
            cout << "Dirigivel carregado" << endl;
        }else if(nome == "Loja"){
            objetos.push_back(new Loja());
             objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
            cout << "Loja carregada" << endl;
        }else if(nome == "Arvore"){
            objetos.push_back(new Arvore());
             objetos.back()->carregar(tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
            cout << "Arvore carregada" << endl;
        }
}

void carregar(){
    ifstream arquivo;
    arquivo.open("../Trabalho1/cenatio.txt", ios::app);
    if(arquivo.is_open()){
        while (!arquivo.eof()) {
            string nome = "";
            GLfloat tx = 0, ty = 0, tz = 0;
            GLfloat ax = 0, ay = 0, az = 0;
            GLfloat sx = 0, sy = 0, sz = 0;
            bool selecionado, eixo;
            arquivo >> nome;
            arquivo >> tx >> ty >> tz;
            arquivo >> ax >> ay >> az;
            arquivo >> sx >> sy >> sz;
            arquivo >> selecionado >> eixo;
            cout << nome << endl;
            gerarObj(nome,tx,ty,tx,ax,ay,az,sx,sy,sz,selecionado,eixo);
        }
    }else{
        cout << "Arquivo nao foi possicel ser aberto" << endl;
    }
}

void gravar(){
    ofstream arquivo;
    arquivo.open("../Trabalho1/cenatio.txt", ios::app);
    arquivo.clear();
    if(!arquivo.is_open()){
        cout << "Arquivo nao foi possicel ser aberto" << endl;
    }else{
        for(int i = 0; i < objetos.size(); i++){
            arquivo << objetos[i]->nome << " ";
            arquivo<<objetos[i]->t.x << " ";
            arquivo<<objetos[i]->t.y << " ";
            arquivo<<objetos[i]->t.z << " ";
            arquivo<<objetos[i]->a.x << " ";
            arquivo<<objetos[i]->a.y << " ";
            arquivo<<objetos[i]->a.z << " ";
            arquivo<<objetos[i]->s.x << " ";
            arquivo<<objetos[i]->s.y << " ";
            arquivo<<objetos[i]->s.z << " ";
            arquivo<<objetos[i]->selecionado << " ";
            arquivo<<objetos[i]->origem << endl;
//            arquivo<<objetos[i]->malha << endl;
        }
    }

    arquivo.close();
}

void desenhaOrigem(){
    for(int i = 0; i < objetos.size(); i++){
        if(objetos[i]->selecionado){
            objetos[i]->origem = !objetos[i]->origem;
        }
     }
}

bool incluirObjeto = false;

void teclado(unsigned char key, int x, int y) {
    //if (!incluirObjeto) {
        GUI::keyInit(key,x,y);
    //}

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'w':
        if(!incluirObjeto){
            gravar();
        }
        break;
    case 'W':
        if(!incluirObjeto){
            cout << "list size " << objetos.size() << endl;
            carregar();
        }
        break;
    case 'l':
        if(!incluirObjeto){
            glutGUI::trans_luz = !glutGUI::trans_luz;
        }else{
            objetos.push_back( new Loja() );
        }
        break;

    case 'n':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;
    case 'b':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;


    case 'O':
        incluirObjeto = !incluirObjeto;
        break;
    case 'r':
        if(incluirObjeto){

        }else{
            desenhaOrigem();
        }
        break;
    case 'p':
        if (incluirObjeto) {
            objetos.push_back( new Predio());
        }
        break;
    case 'u':
        if (incluirObjeto) {
            objetos.push_back( new Asfalto() );
        }
        break;
    case 'D':
        if (!incluirObjeto) {
            objetos.pop_back();
        }
        break;
    case 'd':
        if (!incluirObjeto) {
            //Aqui apaga o obj selecionado
            for (int i = 0; i < objetos.size(); ++i) {
                if(objetos[i]->selecionado){
                    objetos.erase(objetos.begin()+i);
                }
            }
        }else{
            objetos.push_back( new Dirigivel());
        }
        break;
    case 'a':
        if (incluirObjeto) {
            objetos.push_back( new Ambulancia() );
        }
        break;
    case 'A':
        if (incluirObjeto) {
            objetos.push_back( new Arvore() );
        }
        break;
    case 'j':
        //Por alguma razao, adicionar um obj com a letra j causa um bug, interacoes tornam-se diferente do esperado.
        if (incluirObjeto) {
//            objetos.push_back( new Loja() );
        }
        break;
    case 'c':
        if (incluirObjeto) {
            objetos.push_back( new Casa());
        }
        break;
    case 'C':
        if (incluirObjeto) {
            objetos.push_back( new Caminhao());
        }
        break;

    default:
        break;
    }
}

int main()
{
    cout << "Mapa do Teclado" << endl;
    cout << "Comandos de inclusao de objs" << endl;
    cout << "c - Casa" << endl;
    cout << "C - Caminhao" << endl;
    cout << "a - Ambulancia" << endl;
    cout << "A - Arvore" << endl;
    cout << "d - Dirigivel" << endl;
    cout << "u - Asfalto" << endl;
    cout << "p - Predio" << endl;
    cout << "l - Loja" << endl;
    cout << "Comandos com inclusao de obj desativada" << endl;
    cout << "d - deleta objeto selecionado" << endl;
    cout << "D - deleta o ultimo objeto do vetor" << endl;
    cout << "n - Seleciona obj seguinte" << endl;
    cout << "b - seleciona obj anterior" << endl;
    cout << "r - desenha/apaga sistama de coordenadas local" << endl;
    cout << "Comendos padrao" << endl;
    cout << "X/x rotaciona o cenario no eixo x (Global)" << endl;
    cout << "Y/y rotaciona o cenario no eixo y (Global)" << endl;
    cout << "Z/z zoom in e out" << endl;
    iniciarVectror();
    GUI gui = GUI(800,600,desenha,teclado);
}
