#include "./OpenGL/GLEW/include/glew.h"
#include "./OpenGL/GLFW/include/glfw3.h"
#include "./OpenGL/glm/glm/glm.hpp"
#include"./OpenGL/glm/glm/gtc/type_ptr.hpp"


#include <string.h>
#include "Mesh.h"

Mesh::Mesh(const char* filename)
{
    //LoadObjModel(filename);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &vertex);
	glBindBuffer(GL_ARRAY_BUFFER, vertex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(hardvertices), hardvertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
}

void Mesh::draw() {

	glBindVertexArray(VAO); 
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
}

/*void Mesh::LoadObjModel(const char* filename)
{
    std::ifstream in(filename, std::ios::in);
    if (!in)
    {
        std::cerr<<"Cannot open "<<filename<< std::endl;
        exit(1);

    }
    std::string line;
    int finInd = 0;
    while (std::getline(in, line))
    {

        if (line[0] == 'v' && line[1] == ' ') {
            std::istringstream v(line);
            glm::vec3 vert;
            double x, y, z;
            v >> x;
            v >> y;
            v >> z;
            vert = glm::vec3(x, y, z);
            vertices.push_back(vert);
        }
        else if (line[0] == 'f') {
            std::istringstream v(line.substr(2));
            std::string a, b, c;
            v >> a;
            v >> b;
            v >> c;

            GLuint m, n, o;
            m = (int)a[0];
            n = (int)b[0];
            o = (int)c[0];
            //a--;
            //b--;
            //c--;
            std::cout << a  << " " << b << " " << c << std::endl;
            /*newVert[finInd] = (float)vertices[a].x;
            finInd++;
            newVert[finInd] = (float)vertices[a].y;
            finInd++;
            newVert[finInd] = (float)vertices[a].z;
            finInd++;

            newVert[finInd] = (float)vertices[b].x;
            finInd++;
            newVert[finInd] = (float)vertices[b].y;
            finInd++;
            newVert[finInd] = (float)vertices[b].z;
            finInd++;

            newVert[finInd] = (float)vertices[c].x;
            finInd++;
            newVert[finInd] = (float)vertices[c].y;
            finInd++;
            newVert[finInd] = (float)vertices[c].z;
            finInd++;

            faceIndex.push_back(a);
            faceIndex.push_back(b);
            faceIndex.push_back(c);
        }

    }*/

    //calculate all mesh vertices using face index
    /* for (unsigned int i = 0; i < faceIndex.size(); i++)
    {
        std::cout << finInd << std::endl;
        glm::vec3 meshData;
        meshData = glm::vec3(vertices[faceIndex[i]].x, vertices[faceIndex[i]].y, vertices[faceIndex[i]].z);
        newVert[finInd] = (float)vertices[faceIndex[i]].x;
        finInd++;
        newVert[finInd] = (float)vertices[faceIndex[i]].y;
        finInd++;
        newVert[finInd] = (float)vertices[faceIndex[i]].z;
        finInd++;

        //meshVertices.push_back(meshData);

    } 

    if (finInd == 216) {
        std::cout << "YES******************************" << std::endl;
    }

    else {
        std::cout << "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO " << finInd << std::endl;
    }
}

//function for returing mesh vertex data
std::vector<glm::vec3> Mesh::returnMesh()
{
    return meshVertices;
}*/