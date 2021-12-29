#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMimeDatabase>
#include <QMultiHash>

class QFileInfo;
class QTreeWidget;
class QListWidget;
class QPushButton;

class SelectDefaultApplication : public QWidget {
	Q_OBJECT

public:
	SelectDefaultApplication(QWidget *parent = nullptr);
	~SelectDefaultApplication();

private slots:
	void onMimetypeSelected();
	void onSetDefaultClicked();

private:
	void loadDesktopFile(const QFileInfo &fileInfo);
	void setDefault(const QString &appName, const QSet<QString> &mimetypes,
			const QSet<QString> &unselectedMimetypes);
	void loadIcons(const QString &path);

	QMultiHash<QString, QString> m_supportedMimetypes;
	QMultiHash<QString, QString> m_childMimeTypes;
	QHash<QString, QSet<QString> > m_applications;
	QHash<QString, QString> m_applicationIcons;
	QHash<QString, QString> m_applicationNames;
	QHash<QString, QString> m_desktopFileNames;

	QHash<QString, QString> m_appIdToDesktopFile;

	QHash<QString, QIcon>
		m_mimeTypeIcons; // for preloading icons, because that's (a bit) slooow
	QHash<QString, QString> m_iconPaths;

	QTreeWidget *m_applicationList;
	QMimeDatabase m_mimeDb;
	QListWidget *m_mimetypeList;
	QPushButton *m_setDefaultButton;
};

#endif // WIDGET_H
