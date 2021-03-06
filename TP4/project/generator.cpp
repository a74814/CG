#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
float pi = M_PI;
void plano(char* c, char* f){
    double l = atof(c);
    ofstream ficheiro;
    ficheiro.open(f, ios::app);

    if (ficheiro.is_open()) {
        ficheiro << "0" << " 0 " << -(l/2) << "\n";
        ficheiro << "0" << " 0 " << l/2 << "\n";
        ficheiro << l/2 << " 0 " << "0" << "\n";

        ficheiro << "0" << " 0 " << l/2 << "\n";
        ficheiro << "0" << " 0 " << -(l/2) << "\n";
        ficheiro << -(l/2) << " 0 " << "0" << "\n";
    }
    ficheiro.close();
}

void caixa(char* comprimento, char* alt, char* largura, char* divisao, char* f){
    double altura = atof(alt);
    double div = atof(divisao)+1;
    double comp = atof(comprimento);
    double larg = atof(largura);

    ofstream ficheiro;
    ficheiro.open(f, ios::app);

    if (ficheiro.is_open()) {
        float c = comp / div;
        float a = altura / div;
        float l = larg / div;
        float cini = c;
        float lini = l;
        float aini = a;
        for (c; c <= comp; c += cini) {
            for (l; l <= larg; l += lini) {
                for (a; a <= altura; a += aini) {
                    //face superior
                    ficheiro << c << " " << altura << " " << l << "\n";
                    ficheiro << c-cini << " " << altura << " " << l-lini << "\n";
                    ficheiro << c-cini << " " << altura << " " << l << "\n";
                    ficheiro << c << " " << altura << " " << l-lini << "\n";
                    ficheiro << c-cini << " " << altura << " " << l-lini << "\n";
                    ficheiro << c << " " << altura << " " << l << "\n";
                    //face inferior
                    ficheiro << c << " 0 " << l << "\n";
                    ficheiro << c-cini << " 0 " << l << "\n";
                    ficheiro << c-cini << " 0 " << l-lini << "\n";
                    ficheiro << c << " 0 " << l << "\n";
                    ficheiro << c-cini << " 0 " << l-lini << "\n";
                    ficheiro << c << " 0 " << l-lini << "\n";
                    //frente
                    ficheiro << comp << " " << a-aini << " " << l << "\n";
                    ficheiro << comp << " " << a - aini << " " << l-lini << "\n";
                    ficheiro << comp << " " << a << " " << l << "\n";
                    ficheiro << comp << " " << a - aini << " " << l-lini << "\n";
                    ficheiro << comp << " " << a << " " << l-lini << "\n";
                    ficheiro << comp << " " << a << " " << l << "\n";
                    //verso
                    ficheiro << "0 " << a << " " << l << "\n";
                    ficheiro << "0 " << a-aini << " " << l-lini << "\n";
                    ficheiro << "0 " << a-aini << " " << l << "\n";
                    ficheiro << "0 " << a << " " << l-lini << "\n";
                    ficheiro << "0 " << a-aini << " " << l-lini << "\n";
                    ficheiro << "0 " << a << " " << l << "\n";
                    //esquerda
                    ficheiro << c-cini << " " << a-aini << " " << larg << "\n";
                    ficheiro << c << " " << a - aini << " " << larg << "\n";
                    ficheiro << c << " " << a << " " << larg << "\n";
                    ficheiro << c - cini << " " << a << " " << larg << "\n";
                    ficheiro << c - cini << " " << a - aini << " " << larg << "\n";
                    ficheiro << c << " " << a << " " << larg << "\n";
                    //direita
                    ficheiro << c - cini << " " << a - aini << " 0\n";
                    ficheiro << c - cini << " " << a << " 0\n";
                    ficheiro << c << " " << a << " 0\n";
                    ficheiro << c - cini << " " << a - aini << " 0\n";
                    ficheiro << c << " " << a << " 0\n";
                    ficheiro << c << " " << a - aini << " 0\n";
                }
                a = aini;
            }
            l = lini;
        }
    }
    ficheiro.close();
}

void esfera(char* r, char* p, char* st, char* f) {
    int stacks = atoi(st);
    int raio = atof(r);
    int slices = atoi(p);


    double alfa = 0;//horizontal
    double deltaAlfa = (2 * pi) / slices;//varia��o horizontal
    double beta = 0;//vertical
    double deltaBeta = pi / stacks;//varia��o vertical

    double ponto1x, ponto1y, ponto1z;
    double ponto2x, ponto2y, ponto2z;
    double ponto3x, ponto3y, ponto3z;
    double ponto4x, ponto4y, ponto4z;

    double s;
    double t;
    double deltaS = 1.0f / slices;
    double deltaT = 1.0f / stacks;
    ofstream ficheiro;
    ficheiro.open(f, ios::app);
    if (ficheiro.is_open()) {
        for (int i = 0; i < stacks; i++) {
            alfa = 0;
            t = (stacks - i) * deltaT;
            for (int j = 0; j < slices; j++) {
                s = j * deltaS;
                ponto1x = raio * sin(beta) * sin(alfa);
                ponto1y = raio * cos(beta);
                ponto1z = raio * sin(beta) * cos(alfa);

                ponto2x = raio * sin(beta + deltaBeta) * sin(alfa);
                ponto2y = raio * cos(beta + deltaBeta);
                ponto2z = raio * sin(beta + deltaBeta) * cos(alfa);

                ponto3x = raio * sin(beta) * sin(alfa + deltaAlfa);
                ponto3y = raio * cos(beta);
                ponto3z = raio * sin(beta) * cos(alfa + deltaAlfa);

                ponto4x = raio * sin(beta + deltaBeta) * sin(alfa + deltaAlfa);
                ponto4y = raio * cos(beta + deltaBeta);
                ponto4z = raio * sin(beta + deltaBeta) * cos(alfa + deltaAlfa);

                ficheiro << ponto1x << " " << ponto1y << " " << ponto1z << "\n";
                ficheiro << sin(beta) * sin(alfa) << " " << cos(beta) << " " << sin(beta) * cos(alfa) << "\n";
                ficheiro << s << " " << t << " " << -1 << "\n";

                ficheiro << ponto4x << " " << ponto4y << " " << ponto4z << "\n";
                ficheiro << sin(beta + deltaBeta) * sin(alfa + deltaAlfa) << " " << cos(beta + deltaBeta) << " " << sin(beta + deltaBeta) * cos(alfa + deltaAlfa) << "\n";
                ficheiro << (s + deltaS) << " " << (t - deltaT) << " " << -1 << "\n";

                ficheiro << ponto3x << " " << ponto3y << " " << ponto3z << "\n";
                ficheiro << sin(beta) * sin(alfa + deltaAlfa) << " " << cos(beta) << " " << sin(beta) * cos(alfa + deltaAlfa) << "\n";
                ficheiro << (s + deltaS) << " " << t << " " << -1 << "\n";


                ficheiro << ponto1x << " " << ponto1y << " " << ponto1z << "\n";
                ficheiro << sin(beta) * sin(alfa) << " " << cos(beta) << " " << sin(beta) * cos(alfa) << "\n";
                ficheiro << s << " " << t << " " << -1 << "\n";

                ficheiro << ponto2x << " " << ponto2y << " " << ponto2z << "\n";
                ficheiro << sin(beta + deltaBeta) * sin(alfa) << " " << cos(beta + deltaBeta) << " " << sin(beta + deltaBeta) * cos(alfa) << "\n";
                ficheiro << s << " " << (t - deltaT) << " " << -1 << "\n";

                ficheiro << ponto4x << " " << ponto4y << " " << ponto4z << "\n";
                ficheiro << sin(beta + deltaBeta) * sin(alfa + deltaAlfa) << " " << cos(beta + deltaBeta) << " " << sin(beta + deltaBeta) * cos(alfa + deltaAlfa) << "\n";
                ficheiro << (s + deltaS) << " " << (t - deltaT) << " " << -1 << "\n";

                alfa += deltaAlfa;
            }
            beta += deltaBeta;
        }
    }
    ficheiro.close();
}

void cone(char* raio, char* altura, char* partes, char* f){
    double l = atof(altura);
    double r = atof(raio);
    int p = atoi(partes);
    ofstream ficheiro;
    ficheiro.open(f, ios::app);

    if (ficheiro.is_open()) {
        //circulo inferior
        for (int a = 0; a < 360; a += 360 / p) {
            double h1 = a * pi / 180;
            int n = a + 360 / p;
            double h2 = n * pi / 180;

            ficheiro << sin(h1) * r << " 0 " << cos(h1) * r << "\n";
            ficheiro << "0" << " 0 " << "0" << "\n";
            ficheiro << sin(h2) * r << " 0 " << cos(h2) * r << "\n";
        }
        //faces
        for (int a = 0; a < 360; a += 360 / p) {
            double h1 = a * pi / 180;
            int n = a + 360 / p;
            double h2 = n * pi / 180;
            ficheiro << "0"<< " " << l << " " << "0" << "\n";
            ficheiro << sin(h1) * r << " 0 " << cos(h1) * r << "\n";
            ficheiro << sin(h2) * r << " 0 " << cos(h2) * r << "\n";
        }
    }
    ficheiro.close();
}



int main(int argc, char** argv) {
    // Plane(length, filename)
    if (strcmp(argv[1], "plane") == 0) {
        if (argc == 4 && atoi(argv[2])>0) plano(argv[2], argv[3]);
        else printf("Input Invalido\nPara desenhar plano insira comprimento e nome do ficheiro\n");
    }
    // Box(length, height, width, divisions, filename)
    if (strcmp(argv[1], "box") == 0){
        if (argc == 7 && atoi(argv[2]) > 0 && atoi(argv[3]) > 0 && atoi(argv[4]) > 0 && atoi(argv[5]) >= 0) caixa(argv[2], argv[3], argv[4], argv[5], argv[6]);
        else printf("Input Invalido\nPara desenhar caixa insira comprimento, altura, largura, divisoes e nome do ficheiro\n");
    }
    // Sphere(radius, slices, stacks, filename)
    if (strcmp(argv[1], "sphere") == 0) {
        if (argc == 6) esfera(argv[2], argv[3], argv[4], argv[5]);
        else printf("Input Invalido\nPara desenhar esfera insira raio, cortes, stacks e nome do ficheiro\n");
    }
    // Cone(radius, height, slices, filename)
    if (strcmp(argv[1], "cone") == 0) {
        if (argc == 6 && atoi(argv[4]) > 2 && atoi(argv[2]) > 0 && atoi(argv[3]) > 0 && atoi(argv[4]) > 0) cone(argv[2], argv[3], argv[4], argv[5]);
        else printf("Input Invalido\nPara desenhar cone insira raio, altura, cortes e nome do ficheiro\n");
    }
    if (strcmp(argv[1], "cone") != 0 && strcmp(argv[1], "sphere") != 0 && strcmp(argv[1], "box") != 0 && strcmp(argv[1], "plane") != 0) 
        printf("Input Inv�lido\nEscreva plane, box, sphere ou cone\n");
    return 0;
}