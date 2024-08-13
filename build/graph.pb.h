// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: graph.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_graph_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_graph_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_graph_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_graph_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_graph_2eproto;
class Graph;
class GraphDefaultTypeInternal;
extern GraphDefaultTypeInternal _Graph_default_instance_;
class Node;
class NodeDefaultTypeInternal;
extern NodeDefaultTypeInternal _Node_default_instance_;
class NodeRef;
class NodeRefDefaultTypeInternal;
extern NodeRefDefaultTypeInternal _NodeRef_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Graph* Arena::CreateMaybeMessage<::Graph>(Arena*);
template<> ::Node* Arena::CreateMaybeMessage<::Node>(Arena*);
template<> ::NodeRef* Arena::CreateMaybeMessage<::NodeRef>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class NodeRef PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:NodeRef) */ {
 public:
  inline NodeRef() : NodeRef(nullptr) {};
  virtual ~NodeRef();

  NodeRef(const NodeRef& from);
  NodeRef(NodeRef&& from) noexcept
    : NodeRef() {
    *this = ::std::move(from);
  }

  inline NodeRef& operator=(const NodeRef& from) {
    CopyFrom(from);
    return *this;
  }
  inline NodeRef& operator=(NodeRef&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const NodeRef& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NodeRef* internal_default_instance() {
    return reinterpret_cast<const NodeRef*>(
               &_NodeRef_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(NodeRef& a, NodeRef& b) {
    a.Swap(&b);
  }
  inline void Swap(NodeRef* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(NodeRef* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline NodeRef* New() const final {
    return CreateMaybeMessage<NodeRef>(nullptr);
  }

  NodeRef* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<NodeRef>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const NodeRef& from);
  void MergeFrom(const NodeRef& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(NodeRef* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "NodeRef";
  }
  protected:
  explicit NodeRef(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_graph_2eproto);
    return ::descriptor_table_graph_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNodeIdxFieldNumber = 1,
    kConnIdxFieldNumber = 2,
  };
  // int32 node_idx = 1;
  void clear_node_idx();
  ::PROTOBUF_NAMESPACE_ID::int32 node_idx() const;
  void set_node_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_node_idx() const;
  void _internal_set_node_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 conn_idx = 2;
  void clear_conn_idx();
  ::PROTOBUF_NAMESPACE_ID::int32 conn_idx() const;
  void set_conn_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_conn_idx() const;
  void _internal_set_conn_idx(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:NodeRef)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 node_idx_;
  ::PROTOBUF_NAMESPACE_ID::int32 conn_idx_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// -------------------------------------------------------------------

class Node PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Node) */ {
 public:
  inline Node() : Node(nullptr) {};
  virtual ~Node();

  Node(const Node& from);
  Node(Node&& from) noexcept
    : Node() {
    *this = ::std::move(from);
  }

  inline Node& operator=(const Node& from) {
    CopyFrom(from);
    return *this;
  }
  inline Node& operator=(Node&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Node& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Node* internal_default_instance() {
    return reinterpret_cast<const Node*>(
               &_Node_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Node& a, Node& b) {
    a.Swap(&b);
  }
  inline void Swap(Node* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Node* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Node* New() const final {
    return CreateMaybeMessage<Node>(nullptr);
  }

  Node* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Node>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Node& from);
  void MergeFrom(const Node& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Node* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Node";
  }
  protected:
  explicit Node(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_graph_2eproto);
    return ::descriptor_table_graph_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kInRefFieldNumber = 4,
    kOutRefFieldNumber = 5,
    kContextFieldNumber = 6,
    kIndexFieldNumber = 1,
    kTypeFieldNumber = 2,
    kLayerFieldNumber = 3,
  };
  // repeated .NodeRef in_ref = 4;
  int in_ref_size() const;
  private:
  int _internal_in_ref_size() const;
  public:
  void clear_in_ref();
  ::NodeRef* mutable_in_ref(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >*
      mutable_in_ref();
  private:
  const ::NodeRef& _internal_in_ref(int index) const;
  ::NodeRef* _internal_add_in_ref();
  public:
  const ::NodeRef& in_ref(int index) const;
  ::NodeRef* add_in_ref();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >&
      in_ref() const;

  // repeated .NodeRef out_ref = 5;
  int out_ref_size() const;
  private:
  int _internal_out_ref_size() const;
  public:
  void clear_out_ref();
  ::NodeRef* mutable_out_ref(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >*
      mutable_out_ref();
  private:
  const ::NodeRef& _internal_out_ref(int index) const;
  ::NodeRef* _internal_add_out_ref();
  public:
  const ::NodeRef& out_ref(int index) const;
  ::NodeRef* add_out_ref();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >&
      out_ref() const;

  // bytes context = 6;
  void clear_context();
  const std::string& context() const;
  void set_context(const std::string& value);
  void set_context(std::string&& value);
  void set_context(const char* value);
  void set_context(const void* value, size_t size);
  std::string* mutable_context();
  std::string* release_context();
  void set_allocated_context(std::string* context);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_context();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_context(
      std::string* context);
  private:
  const std::string& _internal_context() const;
  void _internal_set_context(const std::string& value);
  std::string* _internal_mutable_context();
  public:

  // int32 index = 1;
  void clear_index();
  ::PROTOBUF_NAMESPACE_ID::int32 index() const;
  void set_index(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_index() const;
  void _internal_set_index(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 type = 2;
  void clear_type();
  ::PROTOBUF_NAMESPACE_ID::int32 type() const;
  void set_type(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_type() const;
  void _internal_set_type(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 layer = 3;
  void clear_layer();
  ::PROTOBUF_NAMESPACE_ID::int32 layer() const;
  void set_layer(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_layer() const;
  void _internal_set_layer(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:Node)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef > in_ref_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef > out_ref_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr context_;
  ::PROTOBUF_NAMESPACE_ID::int32 index_;
  ::PROTOBUF_NAMESPACE_ID::int32 type_;
  ::PROTOBUF_NAMESPACE_ID::int32 layer_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// -------------------------------------------------------------------

class Graph PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Graph) */ {
 public:
  inline Graph() : Graph(nullptr) {};
  virtual ~Graph();

  Graph(const Graph& from);
  Graph(Graph&& from) noexcept
    : Graph() {
    *this = ::std::move(from);
  }

  inline Graph& operator=(const Graph& from) {
    CopyFrom(from);
    return *this;
  }
  inline Graph& operator=(Graph&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Graph& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Graph* internal_default_instance() {
    return reinterpret_cast<const Graph*>(
               &_Graph_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Graph& a, Graph& b) {
    a.Swap(&b);
  }
  inline void Swap(Graph* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Graph* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Graph* New() const final {
    return CreateMaybeMessage<Graph>(nullptr);
  }

  Graph* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Graph>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Graph& from);
  void MergeFrom(const Graph& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Graph* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Graph";
  }
  protected:
  explicit Graph(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_graph_2eproto);
    return ::descriptor_table_graph_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNodesFieldNumber = 1,
  };
  // repeated .Node nodes = 1;
  int nodes_size() const;
  private:
  int _internal_nodes_size() const;
  public:
  void clear_nodes();
  ::Node* mutable_nodes(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Node >*
      mutable_nodes();
  private:
  const ::Node& _internal_nodes(int index) const;
  ::Node* _internal_add_nodes();
  public:
  const ::Node& nodes(int index) const;
  ::Node* add_nodes();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Node >&
      nodes() const;

  // @@protoc_insertion_point(class_scope:Graph)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Node > nodes_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NodeRef

// int32 node_idx = 1;
inline void NodeRef::clear_node_idx() {
  node_idx_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 NodeRef::_internal_node_idx() const {
  return node_idx_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 NodeRef::node_idx() const {
  // @@protoc_insertion_point(field_get:NodeRef.node_idx)
  return _internal_node_idx();
}
inline void NodeRef::_internal_set_node_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  node_idx_ = value;
}
inline void NodeRef::set_node_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_node_idx(value);
  // @@protoc_insertion_point(field_set:NodeRef.node_idx)
}

// int32 conn_idx = 2;
inline void NodeRef::clear_conn_idx() {
  conn_idx_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 NodeRef::_internal_conn_idx() const {
  return conn_idx_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 NodeRef::conn_idx() const {
  // @@protoc_insertion_point(field_get:NodeRef.conn_idx)
  return _internal_conn_idx();
}
inline void NodeRef::_internal_set_conn_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  conn_idx_ = value;
}
inline void NodeRef::set_conn_idx(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_conn_idx(value);
  // @@protoc_insertion_point(field_set:NodeRef.conn_idx)
}

// -------------------------------------------------------------------

// Node

// int32 index = 1;
inline void Node::clear_index() {
  index_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Node::_internal_index() const {
  return index_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Node::index() const {
  // @@protoc_insertion_point(field_get:Node.index)
  return _internal_index();
}
inline void Node::_internal_set_index(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  index_ = value;
}
inline void Node::set_index(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_index(value);
  // @@protoc_insertion_point(field_set:Node.index)
}

// int32 type = 2;
inline void Node::clear_type() {
  type_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Node::_internal_type() const {
  return type_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Node::type() const {
  // @@protoc_insertion_point(field_get:Node.type)
  return _internal_type();
}
inline void Node::_internal_set_type(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  type_ = value;
}
inline void Node::set_type(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:Node.type)
}

// int32 layer = 3;
inline void Node::clear_layer() {
  layer_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Node::_internal_layer() const {
  return layer_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Node::layer() const {
  // @@protoc_insertion_point(field_get:Node.layer)
  return _internal_layer();
}
inline void Node::_internal_set_layer(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  layer_ = value;
}
inline void Node::set_layer(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_layer(value);
  // @@protoc_insertion_point(field_set:Node.layer)
}

// repeated .NodeRef in_ref = 4;
inline int Node::_internal_in_ref_size() const {
  return in_ref_.size();
}
inline int Node::in_ref_size() const {
  return _internal_in_ref_size();
}
inline void Node::clear_in_ref() {
  in_ref_.Clear();
}
inline ::NodeRef* Node::mutable_in_ref(int index) {
  // @@protoc_insertion_point(field_mutable:Node.in_ref)
  return in_ref_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >*
Node::mutable_in_ref() {
  // @@protoc_insertion_point(field_mutable_list:Node.in_ref)
  return &in_ref_;
}
inline const ::NodeRef& Node::_internal_in_ref(int index) const {
  return in_ref_.Get(index);
}
inline const ::NodeRef& Node::in_ref(int index) const {
  // @@protoc_insertion_point(field_get:Node.in_ref)
  return _internal_in_ref(index);
}
inline ::NodeRef* Node::_internal_add_in_ref() {
  return in_ref_.Add();
}
inline ::NodeRef* Node::add_in_ref() {
  // @@protoc_insertion_point(field_add:Node.in_ref)
  return _internal_add_in_ref();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >&
Node::in_ref() const {
  // @@protoc_insertion_point(field_list:Node.in_ref)
  return in_ref_;
}

// repeated .NodeRef out_ref = 5;
inline int Node::_internal_out_ref_size() const {
  return out_ref_.size();
}
inline int Node::out_ref_size() const {
  return _internal_out_ref_size();
}
inline void Node::clear_out_ref() {
  out_ref_.Clear();
}
inline ::NodeRef* Node::mutable_out_ref(int index) {
  // @@protoc_insertion_point(field_mutable:Node.out_ref)
  return out_ref_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >*
Node::mutable_out_ref() {
  // @@protoc_insertion_point(field_mutable_list:Node.out_ref)
  return &out_ref_;
}
inline const ::NodeRef& Node::_internal_out_ref(int index) const {
  return out_ref_.Get(index);
}
inline const ::NodeRef& Node::out_ref(int index) const {
  // @@protoc_insertion_point(field_get:Node.out_ref)
  return _internal_out_ref(index);
}
inline ::NodeRef* Node::_internal_add_out_ref() {
  return out_ref_.Add();
}
inline ::NodeRef* Node::add_out_ref() {
  // @@protoc_insertion_point(field_add:Node.out_ref)
  return _internal_add_out_ref();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::NodeRef >&
Node::out_ref() const {
  // @@protoc_insertion_point(field_list:Node.out_ref)
  return out_ref_;
}

// bytes context = 6;
inline void Node::clear_context() {
  context_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Node::context() const {
  // @@protoc_insertion_point(field_get:Node.context)
  return _internal_context();
}
inline void Node::set_context(const std::string& value) {
  _internal_set_context(value);
  // @@protoc_insertion_point(field_set:Node.context)
}
inline std::string* Node::mutable_context() {
  // @@protoc_insertion_point(field_mutable:Node.context)
  return _internal_mutable_context();
}
inline const std::string& Node::_internal_context() const {
  return context_.Get();
}
inline void Node::_internal_set_context(const std::string& value) {
  
  context_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Node::set_context(std::string&& value) {
  
  context_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:Node.context)
}
inline void Node::set_context(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  context_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:Node.context)
}
inline void Node::set_context(const void* value,
    size_t size) {
  
  context_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:Node.context)
}
inline std::string* Node::_internal_mutable_context() {
  
  return context_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Node::release_context() {
  // @@protoc_insertion_point(field_release:Node.context)
  return context_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Node::set_allocated_context(std::string* context) {
  if (context != nullptr) {
    
  } else {
    
  }
  context_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), context,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:Node.context)
}
inline std::string* Node::unsafe_arena_release_context() {
  // @@protoc_insertion_point(field_unsafe_arena_release:Node.context)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return context_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void Node::unsafe_arena_set_allocated_context(
    std::string* context) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (context != nullptr) {
    
  } else {
    
  }
  context_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      context, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Node.context)
}

// -------------------------------------------------------------------

// Graph

// repeated .Node nodes = 1;
inline int Graph::_internal_nodes_size() const {
  return nodes_.size();
}
inline int Graph::nodes_size() const {
  return _internal_nodes_size();
}
inline void Graph::clear_nodes() {
  nodes_.Clear();
}
inline ::Node* Graph::mutable_nodes(int index) {
  // @@protoc_insertion_point(field_mutable:Graph.nodes)
  return nodes_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Node >*
Graph::mutable_nodes() {
  // @@protoc_insertion_point(field_mutable_list:Graph.nodes)
  return &nodes_;
}
inline const ::Node& Graph::_internal_nodes(int index) const {
  return nodes_.Get(index);
}
inline const ::Node& Graph::nodes(int index) const {
  // @@protoc_insertion_point(field_get:Graph.nodes)
  return _internal_nodes(index);
}
inline ::Node* Graph::_internal_add_nodes() {
  return nodes_.Add();
}
inline ::Node* Graph::add_nodes() {
  // @@protoc_insertion_point(field_add:Graph.nodes)
  return _internal_add_nodes();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Node >&
Graph::nodes() const {
  // @@protoc_insertion_point(field_list:Graph.nodes)
  return nodes_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_graph_2eproto