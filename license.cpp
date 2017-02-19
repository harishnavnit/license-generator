#include "license.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCryptographicHash>


License::License(QObject *parent)
    : QObject(parent),
      m_macAddress(""), m_licenseHash(000), m_expiryDate(QDate::currentDate())
{}

License::License(QString mac, QObject *parent)
    : QObject(parent),
      m_macAddress(mac), m_expiryDate(QDate::currentDate()), m_licenseHash(qHash(m_macAddress))
{}

License::License(QString mac, QDate expiry, QObject *parent)
    : QObject(parent),
      m_macAddress(mac), m_expiryDate(expiry), m_licenseHash(qHash(m_macAddress))
{}

void License::saveToFile(QString fileName, QString path)
{
    QFile file(fileName);
    QDir::setCurrent(path);

    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
        qDebug() << "Failed to open file.";
        return;
    }

    QTextStream stream(&file);
    stream << m_licenseHash << "\n" << m_expiryDate.toString("ddMMyyyy");
}

QDate License::getExpiryDate() const
{
    return m_expiryDate;
}

uint License::getLicenseHash() const
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
    m_licenseHash = qHash(mac);
    saveToFile("License.txt");
}
