#include <QObject>
#include <QtQml/qqmlregistration.h>

class CoreSingletone : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int thing READ thing WRITE setThing NOTIFY thingChanged FINAL)
    QML_ELEMENT
    QML_SINGLETON

public:
    CoreSingletone(QObject *parent = nullptr) : QObject(parent) {}

    int thing() const { return m_value; }
    void setThing(int v)
    {
        if (v != m_value) {
            m_value = v;
            emit thingChanged();
        }
    }

signals:
    void thingChanged();

private:
    int m_value = 12;
};
