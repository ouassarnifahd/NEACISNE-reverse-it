#ifndef StructuralDesignPatterns_hpp
#define StructuralDesignPatterns_hpp

// #include "Creational Design Patterns.hpp"

namespace StructuralDesignPatterns {

    namespace adapter {

        typedef unsigned Coord;

        class Point {
            private:
                Coord x_;
                Coord y_;
            public:
                Point(const Coord& x = 0, const Coord& y = 0):
                    x_(x), y_(y) {}
                virtual ~Point() = default;
        };

        class Shape;

        class Manipulator {
            private:
                Shape* shape_;
            public:
                Manipulator() = default;
                Manipulator(Shape& shape): shape_(&shape) {}
                virtual ~Manipulator();
        };

        // Target
        class Shape {
            public:
                Shape();
                virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
                virtual Manipulator* CreateManipulator() const;
        };

        // Adaptee
        class TextView {
            public:
                TextView();
                void GetOrigin(Coord& x, Coord& y) const;
                void GetExtent(Coord& width, Coord& height) const;
                virtual bool IsEmpty() const;
        };

        // Adapter
        class TextShape: public Shape {
            public:
                TextShape(TextView* text = nullptr): text_(text) {}
                virtual void BoundingBox(Point& bottomLeft, Point& topRight) const {
                    Coord bottom, left, width, height;
                    text_->GetOrigin(bottom, left);
                    text_->GetExtent(width, height);
                    bottomLeft = Point(bottom, left);
                    topRight = Point(bottom + height, left + width);
                }
                virtual bool IsEmpty() const {
                    return text_->IsEmpty();
                }
                virtual Manipulator* CreateManipulator() const;
            private:
                TextView* text_;
        };

        class TextManipulator: public Manipulator {
            private:
                TextShape* textShape_;
            public:
                TextManipulator(TextShape* textShape): textShape_(new TextShape) {
                    textShape_ = textShape;
                }
                virtual ~TextManipulator ();
        };

        Manipulator* TextShape::CreateManipulator() const {
            return new TextManipulator(this);
        }

    } /* Adapter */

} /* StructuralDesignPatterns */

#endif /* end of include guard: StructuralDesignPatterns_hpp */
