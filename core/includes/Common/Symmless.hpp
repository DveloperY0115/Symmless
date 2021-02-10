#ifndef SYMMLESS_SYMMLESS_HPP 
#define SYMMLESS_SYMMLESS_HPP

namespace Symmless {

#if defined(__NVCC__) || (defined(__clang__) && defined(__CUDA__))
#define SYMMLESS_HOST_DEVICE __forceinline__ __device__ __host__
#define SYMMLESS_DEVICE __forceinline__ __device__
#elif defined(__CUDACC_RTC__)
#define SYMMLESS_HOST_DEVICE __forceinline__ __device__
#define SYMMLESS_DEVICE __forceinline__ __device__
#else
#define SYMMLESS_HOST_DEVICE inline
#endif


}
#endif //SYMMLESS_SYMMLESS_HPP 
