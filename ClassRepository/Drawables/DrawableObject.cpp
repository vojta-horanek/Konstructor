#include "DrawableObject.h"

DrawableObject::DrawableObject()
{
	this->type = "DrawableObject";
}

DrawableObject::~DrawableObject()
{

}

void DrawableObject::resolveTies()
{

}

//----------	file handling    ----------

//input format: name:value,type:value,
void DrawableObject::fromFileString(QString input)
{
	QStringList var_names;
	var_names[0] = "id";
	var_names[1] = "name";
	var_names[2] = "is_constructional";

	QStringList variables = input.split(',');
	for(unsigned long i = 0; i < variables.length() - 1; i++)
	{
		QStringList parts = variables[i].split(":");
		QString var_name = parts[0];
		QString var_value = parts[1];

		switch (var_names.indexOf(var_name)) {
			case 0:
				this->id = QVariant(var_value).toULongLong();
				break;
			case 1:
				this->name = var_value;
				break;
			case 2:
				this->is_constructional = QVariant(var_value).toBool();
				break;
			default:
				break;
		}

	}
}

void DrawableObject::loadRelations(QVector<DrawableObject> * list)
{

}

QString DrawableObject::toFileString()
{
	this->file = "";
	this->fileAddVar("id", this->getId());
    qDebug() << this->getId();
	this->fileAddVar("name", this->getName());
	this->fileAddVar("is_constructional", this->is_constructional);
	return this->file;
}

//----------	getters and setters    ----------

void DrawableObject::setName(QString name)
{
	this->name = name;
}

QString DrawableObject::getName()
{
	return this->name;
}

QString DrawableObject::getType()
{
	return this->type;
}

void DrawableObject::setId(unsigned int id)
{
    this->id = id;
}

unsigned int DrawableObject::getId()
{
	return this->id;
}

//----------	saving    ----------

void DrawableObject::fileAddVar(QString variable, QString value)
{
	this->file += variable + ":" + value + ",";
}

void DrawableObject::fileAddVar(QString variable, double value)
{
    this->fileAddVar(variable, QString::number(value));
}

void DrawableObject::fileAddVar(QString variable, int value)
{
    this->fileAddVar(variable, QString::number(value));
}

void DrawableObject::fileAddVar(QString variable, long value)
{
    this->fileAddVar(variable, QString::number(value));
}

void DrawableObject::fileAddVar(QString variable, unsigned int value)
{
    this->fileAddVar(variable, QString::number(value));
}

void DrawableObject::fileAddVar(QString variable, bool value)
{
    this->fileAddVar(variable, QString::number(value));
}

QString DrawableObject::fileFinish()
{
	this->file = this->type + "{" + this->file + "};";
    return this->file;
}

//----------	QGraphicsItem overrides    ----------

QRectF DrawableObject::boundingRect() const
{
	return QRectF();
}

void DrawableObject::paint(QPainter * painter,
						   const QStyleOptionGraphicsItem * option,
						   QWidget * widget)
{

}