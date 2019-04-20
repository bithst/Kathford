package Unit1.BoxPackage;

public class Box {
    double length;
    double width;
    double height;

    public Box(){
        this.length = 0;
        this.height = 0;
        this.width = 0;
    }

    public Box(double l, double w, double h){
        length = l;
        width = w;
        height = h;
    }

    public Box(double l){
        length = width = height = l;
    }

    public double volume(){
        double vol = length * width * height;
        return vol;
    }

    public void setDimension(double l){
        length = width = height = l;
    }

    public void setDimension(double l, double w, double h){
        length = l;
        width = w;
        height = h;
    }
};


