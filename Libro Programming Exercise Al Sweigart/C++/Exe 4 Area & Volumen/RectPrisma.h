#ifndef CUBE_H
#define CUBE_H

class RectPrisma
{
    public:
        RectPrisma();
        ~RectPrisma();
        RectPrisma(const RectPrisma& other);
        RectPrisma(double height, double length, double width);
        double Get_width() { return _width; }
        void Set_width(double val) { _width = val; }
        double Get_length() { return _length; }
        void Set_length(double val) { _length = val; }
        double Get_height() { return _height; }
        void Set_height(double val) { _height = val; }
        double findArea();
        void showRectPrismaInfo();
    protected:

    private:
        double _width;
        double _length;
        double _height;
        void _setMembers(double width, double length, double height);
};

#endif // CUBE_H
