#include "license.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCryptographicHash>


License::License(QObject *parent)
    : QObject(parent),
      m_macAddress(""), m_expiryDate(QDate::currentDate())
{
    m_licenseHash = QCryptographicHash::hash(QByteArray::fromStdString(m_macAddress.toStdString()), QCryptographicHash::Sha1);
}

License::License(QString mac, QObject *parent)
    : QObject(parent),
      m_macAddress(mac), m_expiryDate(QDate::currentDate())
{
    m_licenseHash = QCryptographicHash::hash(QByteArray::fromStdString(m_macAddress.toStdString()), QCryptographicHash::Sha1);
}

License::License(QString mac, QDate expiry, QObject *parent)
    : QObject(parent),
      m_macAddress(mac), m_expiryDate(expiry)
{
    m_licenseHash = QCryptographicHash::hash(QByteArray::fromStdString(m_macAddress.toStdString()), QCryptographicHash::Sha1);
}

void License::saveToFile(QString fileName, QString path)
{
    QFile file(fileName);
    QDir::setCurrent(path);

    // Write the hashed MAC address
    qDebug() << "Opening file in WriteOnly mode";
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
        qDebug() << "Failed to open file.";
        return;
    }
    file.write(m_licenseHash);
    file.close();

    // Write the expiry date
    qDebug() << "Opening to file in append mode";
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open file in append mode";
        return;
    }
    QTextStream stream(&file);
    stream << "\n" << m_expiryDate.toString("ddMMyyyy");
    file.close();
}

QDate License::getExpiryDate() const
{
    return m_expiryDate;
}

QByteArray License::getLicenseHash() const
{
    return m_licenseHash;
}

QString License::getMacAddress() const
{
    return m_macAddress;
}

void License::setExpiryDate(QDate expiry)
{
    m_expiryDate = expiry;
}

void License::setMacAddress(QString mac)
{
    m_macAddress = mac;
}

void License::generateLicenseHash(QString mac)
{
    m_licenseHash = QCryptographicHash::hash(QByteArray::fromStdString(mac.toStdString()), QCryptographicHash::Sha1);
    saveToFile("License.txt");
}
