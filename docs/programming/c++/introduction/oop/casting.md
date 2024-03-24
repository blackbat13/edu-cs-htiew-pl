# Rzutowanie

## Wstęp

### Przykład - relacja klas

```cpp
class Point {
    public:

    Point(){};
    virtual void translate(int k) = 0;
    virtual void print() = 0;
};

class Point2D: public Point {
    int x, y;
    public:
    Point2D(int x, int y): x(x), y(y) {}

    void translate(int k) {
        x += k;
        y += k;
    }

    void print() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Point3D: public Point {
    int x, y, z;
    public:
    Point3D(int x, int y, int z): x(x), y(y), z(z) {}

    void translate(int k) {
        x += k;
        y += k;
        z += k;
    }

    void print() {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }

    void set(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
```

## Rzutowanie statyczne

### Przykład

```cpp
    Point *point;

    point = new Point2D(1, 2);

    // point->set(2, 5); // error
    static_cast<Point2D*>(point)->set(2,5);

    point->print();
```

## Rzutowanie dynamiczne

### Przykład

```cpp
    srand(time(NULL));

    Point *point;

    if(rand() % 2 == 0) {
        point = new Point2D(1, 2);
    } else {
        point = new Point3D(1, 2 ,3);
    }

    if(auto p = dynamic_cast<Point2D*>(point)) {
        p->set(8, 9);
    }

    if(auto p = dynamic_cast<Point3D*>(point)) {
        p->set(4,5,6);
    }

    point->print();
```