#include <stdio.h>
#include <iostream>
#include <node.h>

namespace IO {
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::NewStringType;
	using v8::Object;
	using v8::String;
	using v8::Value;
	using v8::Number;

	void Print( const FunctionCallbackInfo<Value> & args )
	{
		Isolate * isolate = args.GetIsolate();

		for ( int i = 0; i < args.Length(); i++ )
		{
			Local<Value> arg = args[i];
			if ( arg->IsString() )
			{
				Local<String>		ss = arg->ToString();
				String::Utf8Value	value( ss );
				char			* cc = *value;
				printf( "%s ", cc );
			} else if ( arg->IsNumber() )
			{
				double value = arg.As<Number>()->Value();
				printf( "%lf ", value );
			} else if ( arg->IsObject() )
			{
				printf( "[Object ] " );
			} else {
				printf( "[Another type ] " );
			}
		}
	}


	void Println( const FunctionCallbackInfo<Value> & args )
	{
		Isolate * isolate = args.GetIsolate();

		for ( int i = 0; i < args.Length(); i++ )
		{
			Local<Value> arg = args[i];
			if ( arg->IsString() )
			{
				Local<String>		ss = arg->ToString();
				String::Utf8Value	value( ss );
				char			* cc = *value;
				printf( "%s ", cc );
			} else if ( arg->IsNumber() )
			{
				double value = arg.As<Number>()->Value();
				printf( "%lf ", value );
			} else if ( arg->IsObject() )
			{
				printf( "[Object] " );
			} else {
				printf( "[Another type] " );
			}
		}
		printf( "\n" );
	}


	void Raw_input( const FunctionCallbackInfo<Value> & args )
	{
		Isolate * isolate = args.GetIsolate();

		Local<Value> arg = args[0];
		if ( arg->IsString() )
		{
			Local<String>		ss = arg->ToString();
			String::Utf8Value	value( ss );
			char			* cc = *value;
			printf( "%s ", cc );
		} else if ( arg->IsNumber() )
		{
			double value = arg.As<Number>()->Value();
			printf( "%lf ", value );
		} else if ( arg->IsObject() )
		{
			printf( "[Object] " );
		} else {
			printf( "[Another type] " );
		}

		std::string text;
		std::cin >> text;
		args.GetReturnValue().Set( String::NewFromUtf8(
						   isolate, text.c_str(), NewStringType::kNormal ).ToLocalChecked() );
	}


	void Initialize( Local<Object> exports )
	{
		NODE_SET_METHOD( exports, "print", Print );
		NODE_SET_METHOD( exports, "println", Println );
		NODE_SET_METHOD( exports, "raw_input", Raw_input );
	}


	NODE_MODULE( NODE_GYP_MODULE_NAME, Initialize )
}