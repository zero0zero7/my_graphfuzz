SCHEMA

schema.yaml is auto-generated

revised_schema.yaml has been manually edited to allow inference of the schema to produce the .cpp files

Manual edits:
- APIs marked by "*TODO*"
- virtual APIs in base class are not marked despite being ambiguous. But these APIs will be cause errors and are flagged out when trying to compile fuzz_exec.cpp. Then, just edit them.