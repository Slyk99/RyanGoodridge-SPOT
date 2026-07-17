function params = genDHTable(q, params)
    d1      = q(1,1);
    d2      = q(2,1);
    theta3  = q(3,1);
    theta4  = q(4,1);
    theta5  = q(5,1);
    theta6  = q(6,1);

    params = [
    0, 0, d1, 0;
    0, 0, d2, 0;
    0, 0, 0, theta3 + params.phi;
    0, params.b4, 0, theta4;
    0, params.a5 + params.b5, 0, theta5;
    0, params.a5 + params.b6, 0, theta6;
    0, params.a7 + params.b7, 0, 0;
    ];

end