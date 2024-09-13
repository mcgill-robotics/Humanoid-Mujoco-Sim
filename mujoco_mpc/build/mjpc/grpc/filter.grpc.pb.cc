// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: filter.proto

#include "filter.pb.h"
#include "filter.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace filter {

static const char* StateEstimation_method_names[] = {
  "/filter.StateEstimation/Init",
  "/filter.StateEstimation/Reset",
  "/filter.StateEstimation/Update",
  "/filter.StateEstimation/State",
  "/filter.StateEstimation/Covariance",
  "/filter.StateEstimation/Noise",
};

std::unique_ptr< StateEstimation::Stub> StateEstimation::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< StateEstimation::Stub> stub(new StateEstimation::Stub(channel, options));
  return stub;
}

StateEstimation::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Init_(StateEstimation_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Reset_(StateEstimation_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Update_(StateEstimation_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_State_(StateEstimation_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Covariance_(StateEstimation_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Noise_(StateEstimation_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status StateEstimation::Stub::Init(::grpc::ClientContext* context, const ::filter::InitRequest& request, ::filter::InitResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::filter::InitRequest, ::filter::InitResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Init_, context, request, response);
}

void StateEstimation::Stub::async::Init(::grpc::ClientContext* context, const ::filter::InitRequest* request, ::filter::InitResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::filter::InitRequest, ::filter::InitResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Init_, context, request, response, std::move(f));
}

void StateEstimation::Stub::async::Init(::grpc::ClientContext* context, const ::filter::InitRequest* request, ::filter::InitResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Init_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::filter::InitResponse>* StateEstimation::Stub::PrepareAsyncInitRaw(::grpc::ClientContext* context, const ::filter::InitRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::filter::InitResponse, ::filter::InitRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Init_, context, request);
}

::grpc::ClientAsyncResponseReader< ::filter::InitResponse>* StateEstimation::Stub::AsyncInitRaw(::grpc::ClientContext* context, const ::filter::InitRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncInitRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StateEstimation::Stub::Reset(::grpc::ClientContext* context, const ::filter::ResetRequest& request, ::filter::ResetResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::filter::ResetRequest, ::filter::ResetResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Reset_, context, request, response);
}

void StateEstimation::Stub::async::Reset(::grpc::ClientContext* context, const ::filter::ResetRequest* request, ::filter::ResetResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::filter::ResetRequest, ::filter::ResetResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Reset_, context, request, response, std::move(f));
}

void StateEstimation::Stub::async::Reset(::grpc::ClientContext* context, const ::filter::ResetRequest* request, ::filter::ResetResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Reset_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::filter::ResetResponse>* StateEstimation::Stub::PrepareAsyncResetRaw(::grpc::ClientContext* context, const ::filter::ResetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::filter::ResetResponse, ::filter::ResetRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Reset_, context, request);
}

::grpc::ClientAsyncResponseReader< ::filter::ResetResponse>* StateEstimation::Stub::AsyncResetRaw(::grpc::ClientContext* context, const ::filter::ResetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncResetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StateEstimation::Stub::Update(::grpc::ClientContext* context, const ::filter::UpdateRequest& request, ::filter::UpdateResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::filter::UpdateRequest, ::filter::UpdateResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Update_, context, request, response);
}

void StateEstimation::Stub::async::Update(::grpc::ClientContext* context, const ::filter::UpdateRequest* request, ::filter::UpdateResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::filter::UpdateRequest, ::filter::UpdateResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, std::move(f));
}

void StateEstimation::Stub::async::Update(::grpc::ClientContext* context, const ::filter::UpdateRequest* request, ::filter::UpdateResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::filter::UpdateResponse>* StateEstimation::Stub::PrepareAsyncUpdateRaw(::grpc::ClientContext* context, const ::filter::UpdateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::filter::UpdateResponse, ::filter::UpdateRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Update_, context, request);
}

::grpc::ClientAsyncResponseReader< ::filter::UpdateResponse>* StateEstimation::Stub::AsyncUpdateRaw(::grpc::ClientContext* context, const ::filter::UpdateRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncUpdateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StateEstimation::Stub::State(::grpc::ClientContext* context, const ::filter::StateRequest& request, ::filter::StateResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::filter::StateRequest, ::filter::StateResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_State_, context, request, response);
}

void StateEstimation::Stub::async::State(::grpc::ClientContext* context, const ::filter::StateRequest* request, ::filter::StateResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::filter::StateRequest, ::filter::StateResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_State_, context, request, response, std::move(f));
}

void StateEstimation::Stub::async::State(::grpc::ClientContext* context, const ::filter::StateRequest* request, ::filter::StateResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_State_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::filter::StateResponse>* StateEstimation::Stub::PrepareAsyncStateRaw(::grpc::ClientContext* context, const ::filter::StateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::filter::StateResponse, ::filter::StateRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_State_, context, request);
}

::grpc::ClientAsyncResponseReader< ::filter::StateResponse>* StateEstimation::Stub::AsyncStateRaw(::grpc::ClientContext* context, const ::filter::StateRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncStateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StateEstimation::Stub::Covariance(::grpc::ClientContext* context, const ::filter::CovarianceRequest& request, ::filter::CovarianceResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::filter::CovarianceRequest, ::filter::CovarianceResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Covariance_, context, request, response);
}

void StateEstimation::Stub::async::Covariance(::grpc::ClientContext* context, const ::filter::CovarianceRequest* request, ::filter::CovarianceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::filter::CovarianceRequest, ::filter::CovarianceResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Covariance_, context, request, response, std::move(f));
}

void StateEstimation::Stub::async::Covariance(::grpc::ClientContext* context, const ::filter::CovarianceRequest* request, ::filter::CovarianceResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Covariance_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::filter::CovarianceResponse>* StateEstimation::Stub::PrepareAsyncCovarianceRaw(::grpc::ClientContext* context, const ::filter::CovarianceRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::filter::CovarianceResponse, ::filter::CovarianceRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Covariance_, context, request);
}

::grpc::ClientAsyncResponseReader< ::filter::CovarianceResponse>* StateEstimation::Stub::AsyncCovarianceRaw(::grpc::ClientContext* context, const ::filter::CovarianceRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCovarianceRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StateEstimation::Stub::Noise(::grpc::ClientContext* context, const ::filter::NoiseRequest& request, ::filter::NoiseResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::filter::NoiseRequest, ::filter::NoiseResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Noise_, context, request, response);
}

void StateEstimation::Stub::async::Noise(::grpc::ClientContext* context, const ::filter::NoiseRequest* request, ::filter::NoiseResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::filter::NoiseRequest, ::filter::NoiseResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Noise_, context, request, response, std::move(f));
}

void StateEstimation::Stub::async::Noise(::grpc::ClientContext* context, const ::filter::NoiseRequest* request, ::filter::NoiseResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Noise_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::filter::NoiseResponse>* StateEstimation::Stub::PrepareAsyncNoiseRaw(::grpc::ClientContext* context, const ::filter::NoiseRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::filter::NoiseResponse, ::filter::NoiseRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Noise_, context, request);
}

::grpc::ClientAsyncResponseReader< ::filter::NoiseResponse>* StateEstimation::Stub::AsyncNoiseRaw(::grpc::ClientContext* context, const ::filter::NoiseRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncNoiseRaw(context, request, cq);
  result->StartCall();
  return result;
}

StateEstimation::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StateEstimation_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StateEstimation::Service, ::filter::InitRequest, ::filter::InitResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StateEstimation::Service* service,
             ::grpc::ServerContext* ctx,
             const ::filter::InitRequest* req,
             ::filter::InitResponse* resp) {
               return service->Init(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StateEstimation_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StateEstimation::Service, ::filter::ResetRequest, ::filter::ResetResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StateEstimation::Service* service,
             ::grpc::ServerContext* ctx,
             const ::filter::ResetRequest* req,
             ::filter::ResetResponse* resp) {
               return service->Reset(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StateEstimation_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StateEstimation::Service, ::filter::UpdateRequest, ::filter::UpdateResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StateEstimation::Service* service,
             ::grpc::ServerContext* ctx,
             const ::filter::UpdateRequest* req,
             ::filter::UpdateResponse* resp) {
               return service->Update(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StateEstimation_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StateEstimation::Service, ::filter::StateRequest, ::filter::StateResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StateEstimation::Service* service,
             ::grpc::ServerContext* ctx,
             const ::filter::StateRequest* req,
             ::filter::StateResponse* resp) {
               return service->State(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StateEstimation_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StateEstimation::Service, ::filter::CovarianceRequest, ::filter::CovarianceResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StateEstimation::Service* service,
             ::grpc::ServerContext* ctx,
             const ::filter::CovarianceRequest* req,
             ::filter::CovarianceResponse* resp) {
               return service->Covariance(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StateEstimation_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StateEstimation::Service, ::filter::NoiseRequest, ::filter::NoiseResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StateEstimation::Service* service,
             ::grpc::ServerContext* ctx,
             const ::filter::NoiseRequest* req,
             ::filter::NoiseResponse* resp) {
               return service->Noise(ctx, req, resp);
             }, this)));
}

StateEstimation::Service::~Service() {
}

::grpc::Status StateEstimation::Service::Init(::grpc::ServerContext* context, const ::filter::InitRequest* request, ::filter::InitResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StateEstimation::Service::Reset(::grpc::ServerContext* context, const ::filter::ResetRequest* request, ::filter::ResetResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StateEstimation::Service::Update(::grpc::ServerContext* context, const ::filter::UpdateRequest* request, ::filter::UpdateResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StateEstimation::Service::State(::grpc::ServerContext* context, const ::filter::StateRequest* request, ::filter::StateResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StateEstimation::Service::Covariance(::grpc::ServerContext* context, const ::filter::CovarianceRequest* request, ::filter::CovarianceResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StateEstimation::Service::Noise(::grpc::ServerContext* context, const ::filter::NoiseRequest* request, ::filter::NoiseResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace filter

