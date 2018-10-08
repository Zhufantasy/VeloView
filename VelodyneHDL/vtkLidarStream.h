#ifndef VTKLIDARSTREAM_H
#define VTKLIDARSTREAM_H

#include "vtkLidarProvider.h"

class vtkLidarStreamInternal;

class VTK_EXPORT vtkLidarStream : public vtkLidarProvider
{
public:
  vtkTypeMacro(vtkLidarStream, vtkLidarProvider);
  void PrintSelf(ostream& os, vtkIndent indent);

  int GetNumberOfFrames() override;

  vtkSmartPointer<vtkPolyData> GetFrame(int frameNumber, int wantedNumberOfTrailingFrames = 0) override;

  void Poll();

  void Start();
  void Stop();

  void UnloadFrames();

  int GetCacheSize();
  void SetCacheSize(int cacheSize);

  /**
   * @copydoc vtkLidarStreamInternal::OutputFileName
   */
  std::string GetOutputFile();
  void SetOutputFile(const std::string& filename);

  /**
   * @copydoc NetworkSource::LIDARPort
   */
  int GetLIDARPort();
  void SetLIDARPort(const int);

  /**
   * @copydoc NetworkSource::ForwardedIpAddress
   */
  std::string GetForwardedIpAddress();
  void SetForwardedIpAddress(const std::string& ipAddress);

  /**
   * @copydoc NetworkSource::ForwardedLIDARPort
   */
  int GetForwardedLIDARPort();
  void SetForwardedLIDARPort(const int);

  /**
   * @copydoc NetworkSource::IsForwarding
   */
  bool GetIsForwarding();
  void SetIsForwarding(const bool);

  /**
   * @copydoc NetworkSource::IsCrashAnalysing
   */
  bool GetIsCrashAnalysing();
  void SetIsCrashAnalysing(const bool);

protected:
  vtkLidarStream();
  ~vtkLidarStream();

  virtual int RequestData(vtkInformation* request,
                          vtkInformationVector** inputVector,
                          vtkInformationVector* outputVector);

  virtual int RequestInformation(vtkInformation*, vtkInformationVector**, vtkInformationVector*);

  void SetInterpreter(LidarPacketInterpreter *interpreter);
private:
  vtkLidarStreamInternal* Internal;
  vtkLidarStream(const vtkLidarStream&); // not implemented
  void operator=(const vtkLidarStream&); // not implemented

};

#endif // VTKLIDARSTREAM_H