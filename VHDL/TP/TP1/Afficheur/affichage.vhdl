library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: affichage --

entity affichage is
    Port ( clk : in STD_LOGIC;
           data : in STD_LOGIC_VECTOR (15 downto 0);
           seg : out STD_LOGIC_VECTOR (6 downto 0);
           an : out STD_LOGIC_VECTOR (7 downto 0);
           dp : out STD_LOGIC);
end affichage;

architecture Behavioral of affichage is
    signal sel_s : STD_LOGIC_VECTOR(1 downto 0);
    signal hex_s : STD_LOGIC_VECTOR(3 downto 0);

component diviseur is
    Port ( clk : in STD_LOGIC;
           sel : out STD_LOGIC_VECTOR (1 downto 0));
end component;

component hex_7seg is
    Port ( hex : in  STD_LOGIC_VECTOR (3 downto 0);
           seg : out  STD_LOGIC_VECTOR (6 downto 0));
end component;

component mux_4affi is
    Port ( data_i : in  STD_LOGIC_VECTOR (15 downto 0);
           sel : in  STD_LOGIC_VECTOR (1 downto 0);
           data_o : out  STD_LOGIC_VECTOR (3 downto 0);
           an : out  STD_LOGIC_VECTOR (7 downto 0)
          );
end component;

begin

u1: diviseur port map (
    clk => clk,
    sel => sel_s);

u2: hex_7seg port map(
    hex => hex_s,
    seg => seg);

u3: mux_4affi port map(
    data_i => data,
    sel => sel_s,
    data_o => hex_s,
    an => an);

dp <= '1';
end Behavioral;
