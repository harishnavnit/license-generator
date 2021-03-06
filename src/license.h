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
    QDate getExpiryDate() const;
    QString getMacAddress() const;
    QByteArray getLicenseHash() const;

public slots:
    void setExpiryDate(QDate date);
    void setMacAddress(QString mac);
    void generateLicenseHash(QString mac);

private:
    QDate m_expiryDate;
    QString m_macAddress;
    QByteArray m_licenseHash;
};

#endif // LICENSE_H
