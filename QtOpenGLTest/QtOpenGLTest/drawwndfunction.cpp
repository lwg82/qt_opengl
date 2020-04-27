#include "drawwndfunction.h"
#include <QOpenGLShader>

#include <QCoreApplication>

#define mediump
/*
 * 
 */
DrawWndFunction::DrawWndFunction()
{

}

void    DrawWndFunction::initializeOpenGL()
{

	////////////////////////////////////////////////
    // 着色器
    QString vertex_file = QString("%1/vertex_shader.vert").arg(QCoreApplication::applicationDirPath());
    qDebug() << __FUNCTION__ << vertex_file;
    QOpenGLShader vertex_shader(QOpenGLShader::Vertex);
    if(!vertex_shader.compileSourceFile(vertex_file))
    {
        qDebug() << __FUNCTION__ << vertex_shader.log();
        return;
    }

    QString fragment_file = QString("%1/fragment_shader.frag").arg(QCoreApplication::applicationDirPath());
    QOpenGLShader fragment_shader(QOpenGLShader::Fragment);
    if(!fragment_shader.compileSourceFile(fragment_file))
    {
        qDebug() << __FUNCTION__ << fragment_shader.log();
        return;
    }

    m_ShaderProgram.addShader(&vertex_shader);
    m_ShaderProgram.addShader(&fragment_shader);

    m_ShaderProgram.link();

   // m_ShaderProgram.bind();

	/////////////////////////////////////
   // 顶点数组对象
	glGenVertexArrays(1, m_VAOs);
	//
	glBindVertexArray(m_VAOs[0]);

	// 顶点缓冲对象
	glGenBuffers(1, m_VBOs);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBOs[0]);

	float vertices[] = {
		-0.5f, 0.0f, 0.0f,
		0.5f, 0.0f,0.0f,
		0.0f, 0.866f, 0.0f,
	};
	// 给 VBO 填充顶点数据
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	// 
	/*
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);//告诉程序如何解析顶点数据
	glEnableVertexAttribArray(0);

	
	*/

	

	GLuint pos = m_ShaderProgram.attributeLocation("vPosition");

	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);//告诉程序如何解析顶点数据
	glEnableVertexAttribArray(pos);

	glBindBuffer(GL_ARRAY_BUFFER, 0);//取消VBO的绑定,

	glBindVertexArray(0);   //取消VAO绑定
}


