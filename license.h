#ifndef LICENSE_H
#define LICENSE_H

#include <QDir>
#include <QDate>
#include <QObject>
#include <QString>

class License : public QObject
{
    Q_OBJECT

public:
    // Constructors
    explicit License(QObject *parent=0);
    License(QString mac, QObject *parent=0);
    License(QString mac, QDate expiry, QObject *parent=0);

    // Write the generated license hash and expiry date to a file
    void saveToFile(QString fileName, QString path=QDir::homePath());

    // Getter methods
    uint getLicenseHash() const;
    QDate getExpiryDate() const;
    QString getMacAddress() const;

public slots:
    void setExpiryDate(QDate date);
    void setMacAddress(QString mac);
    void generateLicenseHash(QString mac);

private:
    uint m_licenseHash;
    QDate m_expiryDate;
    QString m_macAddress;
};

#endif // LICENSE_H
