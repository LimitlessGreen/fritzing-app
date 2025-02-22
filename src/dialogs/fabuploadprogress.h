#ifndef FABUPLOADPROGRESS_H
#define FABUPLOADPROGRESS_H

#include <QWidget>
#include <QNetworkReply>

class FabUploadProgress : public QWidget
{
	Q_OBJECT
public:
	explicit FabUploadProgress(QWidget *parent = nullptr);
	void init(QNetworkAccessManager *manager, QString filename);

public Q_SLOTS:
	void doUpload();
	void openInBrowser();

private Q_SLOTS:
	void onRequestUploadFinished();
	void onError(QNetworkReply::NetworkError code);
	void uploadDone();
	void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
	void updateProcessingStatus();

Q_SIGNALS:
	void uploadProgressChanged(int);
	void processProgressChanged(int);
	void processingDone();
	void closeUploadError();

private:
	QNetworkAccessManager *mManager;
	QString mFilepath;
	int mActivity;
	QString mRedirect_url;

	void uploadMultipart(const QUrl &url, const QString &file_path);
	void checkProcessingStatus(QUrl url);
	void httpError(QNetworkReply *reply);
	void apiError(QString message);
};

#endif // FABUPLOADPROGRESS_H
