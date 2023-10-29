#include "Circle.h"
#include "Shape.h"
#include "Point2D.h"
#include "Rectangle.h"
#include "Square.h"
#include "Drawing.h"
#include "List.h"
#include "ListLinked.h"
#include "Node.h"

		Drawing::Drawing(){
		shapes = new ListLinked<Shape*>();
		};

		Drawing::~Drawing(){
			delete shapes;	
		};

		void Drawing::add_front(Shape* shape){
			shapes->prepend(shape);
		};

		void Drawing::add_back(Shape* shape){
			shapes->append(shape);
                };

		void Drawing::print_all(){
			for(int i = 0 ; i < shapes->size() ; i++){
				shapes->get(i)->print();
			};
		};
		
		
		double Drawing::get_area_all_circles(){
			double total = 0 ;
			for(int i = 0 ; i < shapes->size() ; i++){
                                Circle* circles = dynamic_cast<Circle*>(shapes->get(i));
				if(circles != nullptr){
					total += circles->area();
                        	};
			};
			return total;
		};

		void Drawing::move_squares(double incX, double incY){
			for(int i = 0 ; i < shapes->size() ; i++){
                                Square* squares = dynamic_cast<Square*>(shapes->get(i));
                                if(squares != nullptr){
                                        squares->translate(incX , incY);
				};
			};

                };
