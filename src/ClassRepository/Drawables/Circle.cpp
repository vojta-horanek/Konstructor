#include "Circle.h"

Circle::Circle()
{
	this->type = "Circle";
}

Circle::Circle(Point *center_point)
{
	this->type = "Circle";
	this->center_point = center_point;
}

Circle::~Circle(){

}

void Circle::resolveTies()
{
	if(this->lies_on != nullptr)
	{
		this->radius = this->center_point->distanceFrom(this->lies_on->getLocation());
		qDebug() << "resolve circle tie, lies on";
	}
}

//----------	file handling    ----------

void Circle::fromFileString(QString input)
{
	DrawableObject::fromFileString(input);

    QStringList var_names = {
      "radius"
    };

	QStringList variables = input.split(',');
    for(int i = 0; i < variables.length() - 1; i++)
	{
		QStringList parts = variables[i].split(":");
		QString var_name = parts[0];
		QString var_value = parts[1];

		switch (var_names.indexOf(var_name)) {
			case 0:
				this->radius = QVariant(var_value).toDouble();
				break;
			default:
				break;
		}

	}
}

void Circle::loadRelations(QVector<DrawableObject*> *list)
{
    QStringList var_names = {
        "center_point"
    };

    QStringList variables = this->file.split(',');
    for(int i = 0; i < variables.length() - 1; i++)
    {
        QStringList parts = variables[i].split(":");
        QString var_name = parts[0];
        QString var_value = parts[1];

		DrawableObject *obj;

        switch (var_names.indexOf(var_name)) {
            case 0:
                obj = DrawableObject::getById(list, QVariant(var_value).toUInt());
                if(obj->getType() == "Point")
                    this->center_point = (Point*)obj;

                break;
            default:
                break;
        }

    }
}

QString Circle::toFileString()
{
	DrawableObject::toFileString();
	this->fileAddVar("center_point", this->center_point->getId());
	this->fileAddVar("radius", this->radius);
	return this->fileFinish();
}

//----------	getters and setters    ----------

Point *Circle::getCenterPoint()
{
	return this->center_point;
}

double *Circle::getRadius()
{
	return &this->radius;
}

Circle *Circle::setRadius(double value)
{
	this->radius = value;

	return this;
}

Circle *Circle::Clone()
{
	Circle *circle = new Circle(this->center_point);
	circle->setRadius(this->radius);
	circle->setRelationLiesOn(this->lies_on);

	return circle;
}

//----------	Relations    ----------

void Circle::setRelationLiesOn(Point *p)
{
	this->lies_on = p;
}

//----------	QGraphicsItem overrides    ----------

QRectF Circle::boundingRect() const
{
	QPointF top_left_point(
				this->center_point->getLocation() -
				QPointF(radius, radius)
				);

	return QRectF(top_left_point,
			  QSizeF(this->radius + radius,
					 this->radius + radius
					 )
			  );
}

void Circle::paint(QPainter *painter,
				   const QStyleOptionGraphicsItem *option,
				   QWidget *widget)
{
	if(this->hidden)
		return;

	resolveTies();
	painter->drawEllipse(this->boundingRect());
}
